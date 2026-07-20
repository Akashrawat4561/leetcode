#!/usr/bin/env python3
from __future__ import annotations

import re
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
README_PATH = ROOT / "README.md"

STATS_START = "<!-- START_DYNAMIC_STATS -->"
STATS_END = "<!-- END_DYNAMIC_STATS -->"
TABLE_START = "<!-- START_DYNAMIC_TABLE -->"
TABLE_END = "<!-- END_DYNAMIC_TABLE -->"

PROBLEM_DIR_PATTERN = re.compile(r"^\d{4}-.+")

LANGUAGE_MAP = {
    ".cpp": "C++",
    ".sql": "SQL",
    ".py": "Python",
    ".java": "Java",
    ".js": "JavaScript",
    ".ts": "TypeScript",
}


def collect_problem_data(repo_root: Path) -> tuple[list[dict[str, str]], Counter]:
    problems: list[dict[str, str]] = []
    language_counter: Counter = Counter()

    for problem_dir in sorted(repo_root.iterdir()):
        if not problem_dir.is_dir() or not PROBLEM_DIR_PATTERN.match(problem_dir.name):
            continue

        solution_files = [
            file
            for file in problem_dir.iterdir()
            if file.is_file() and file.name.lower() != "readme.md" and file.suffix in LANGUAGE_MAP
        ]
        if not solution_files:
            continue

        primary_solution = sorted(solution_files)[0]
        language_name = LANGUAGE_MAP[primary_solution.suffix]
        language_counter[language_name] += 1

        number, slug = problem_dir.name.split("-", 1)
        title = slug.replace("-", " ").title()
        problems.append(
            {
                "number": number,
                "title": title,
                "folder": problem_dir.name,
                "language": language_name,
            }
        )

    return problems, language_counter


def generate_stats_section(total: int, language_counter: Counter) -> str:
    language_summary = ", ".join(
        f"{language}: {count}" for language, count in sorted(language_counter.items())
    )
    updated_at = datetime.now(timezone.utc).strftime("%Y-%m-%d %H:%M UTC")
    lines = [
        "- **Solved Problems:** "
        f"{total}",
        f"- **Languages:** {language_summary if language_summary else 'N/A'}",
        f"- **Last Updated:** {updated_at}",
    ]
    return "\n".join(lines)


def generate_table_section(problems: list[dict[str, str]]) -> str:
    lines = [
        "| # | Problem | Language |",
        "|---|---------|----------|",
    ]
    for problem in problems:
        lines.append(
            f"| {problem['number']} | [{problem['title']}]({problem['folder']}/README.md) | {problem['language']} |"
        )
    return "\n".join(lines)


def replace_section(content: str, start_marker: str, end_marker: str, section_content: str) -> str:
    pattern = re.compile(
        rf"({re.escape(start_marker)}\n)(.*?)(\n{re.escape(end_marker)})",
        flags=re.DOTALL,
    )
    if not pattern.search(content):
        raise ValueError(f"Missing marker block: {start_marker} ... {end_marker}")
    return pattern.sub(rf"\1{section_content}\3", content)


def main() -> None:
    readme = README_PATH.read_text(encoding="utf-8")
    problems, language_counter = collect_problem_data(ROOT)
    readme = replace_section(
        readme,
        STATS_START,
        STATS_END,
        generate_stats_section(len(problems), language_counter),
    )
    readme = replace_section(
        readme,
        TABLE_START,
        TABLE_END,
        generate_table_section(problems),
    )
    README_PATH.write_text(readme, encoding="utf-8")


if __name__ == "__main__":
    main()

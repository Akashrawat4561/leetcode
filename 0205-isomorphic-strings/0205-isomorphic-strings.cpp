class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>a;
        unordered_map<char, char>b;

        for(int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if(a.count(c1) && a[c1] != c2)
                return false;

            if(b.count(c2) && b[c2] != c1)
                return false;

            a[c1] = c2;
            b[c2] = c1;
        }

        return true;
    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int,int> ans;
        int r = 1;

        for (auto x : temp) {
            if (ans.find(x) == ans.end()) {
                ans[x] = r++;
            }
        }

        vector<int> ans1;
        for (auto x : arr) {
            ans1.push_back(ans[x]);
        }

        return ans1;
    }
};
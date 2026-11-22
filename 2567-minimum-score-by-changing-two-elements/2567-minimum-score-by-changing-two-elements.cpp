class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        if (n <= 3)
            return 0;

        int a = nums[n - 3] - nums[0];
        int b = nums[n - 2] - nums[1];
        int c = nums[n - 1] - nums[2];

        return min(a, min(b, c));
    }
};
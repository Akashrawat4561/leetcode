class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int ans1 = 1;
        int ans2 = 1;
        sort(nums.begin(), nums.end());

        ans1 = nums[n-1] * nums[n-2] * nums[n-3];
        ans2 = nums[0] * nums[1] * nums[n-1];
        return max(ans1,ans2);

    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());

        int max1 = nums[n-1];
        int max2 = nums[n-2];

        long long maxp = (max1-1) * (max2-1);

        return maxp;
    }
};
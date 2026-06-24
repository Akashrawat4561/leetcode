class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int st = 0; 
        int end = n-1;

        int mid = st + (end - st)/2;

        return nums[mid];
    }
};

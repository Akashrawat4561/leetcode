class Solution {
public:
    int thirdMax(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int n = nums.size();
        if(n<2){
            return nums[0];
        }
        if(n < 3){
            return max(nums[0],nums[1]);
        }
        
        return nums[nums.size() - 3];
    }
};
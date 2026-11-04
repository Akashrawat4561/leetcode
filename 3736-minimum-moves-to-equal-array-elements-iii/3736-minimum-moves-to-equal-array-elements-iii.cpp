class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());

    int time = 0;

    for(int i = 0; i < nums.size(); i++) {
        time += maxNum - nums[i];
    }

    return time;
    }
};
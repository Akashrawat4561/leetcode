class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int >s;

        for(int i=0;i<n;i++){
            int rem = target - nums[i];

            if(s.find(rem) != s.end()){
                return{s[rem],i};
            }

            s[nums[i]] = i;
        }
        return {-1,-1};
    }
};
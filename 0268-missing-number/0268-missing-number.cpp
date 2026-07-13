class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int missSum = 0;

        for(int i=0;i<n;i++){
            missSum += nums[i]; 
        }
        for(int i=0;i<=n;i++){
            sum += i; 
        }
        int ans = sum - missSum;
        return ans;
    }
};
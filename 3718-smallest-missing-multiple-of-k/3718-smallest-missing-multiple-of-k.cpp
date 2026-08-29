class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i=1;i<=n+1;i++){
            int check = i * k;
            bool found = false;
            for(int j=0;j<n;j++){
                if(check == nums[j]){
                    found = true;
                    break;
                }
            }
            if(!found){
                return check;
            }
        }
        return -1;
    }
};
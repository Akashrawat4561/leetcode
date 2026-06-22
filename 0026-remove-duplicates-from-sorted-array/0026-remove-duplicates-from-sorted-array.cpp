class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        if(n == 0){
            return 0;
        }
        int idx = 1;

        for(int i=1;i<n;i++){
            if(arr[i] != arr[i-1]){
                arr[idx++] = arr[i];
            }
        }
        return idx;
    }
};
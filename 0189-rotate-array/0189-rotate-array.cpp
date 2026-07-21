class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>arr1(n);

        for(int i=0;i<n;i++){
            int neew = (i+k)%n;
            arr1[neew] = arr[i];
        }
        arr = arr1;
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
    }
};
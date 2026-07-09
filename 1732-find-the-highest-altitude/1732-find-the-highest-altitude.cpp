class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int high = 0;
        for(int i=0;i<gain.size();i++){
            ans += gain[i];
            high = max(high,ans);
        }
        return high;
    }
};
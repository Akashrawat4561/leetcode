class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int sum = 0;
        int j = 1;
        for(int i=0;i<n;i++){
            char ch = s[i];
            int value = 'z' - ch + 1;
            value *= j++;
            sum += value;
        }
        return sum;
    }
};
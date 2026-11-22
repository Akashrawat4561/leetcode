class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        bool bb = false;
        for(int i=0;i<n;i++){
            if(s[i] == 'b'&& i < n-1){
                bb = true;
                if(s[i+1] == 'a'){
                    return false;
                }
            }
        }
        return true;
    }
};
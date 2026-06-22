class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long long ans = 0;
        while(x > 0){
            int m = x % 10;
            ans = ans * 10 + m;
            x = x / 10;
        }
        if(temp == ans){
            return true;
        }
        return false;
    }
};
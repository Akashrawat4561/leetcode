class Solution {
public:

    int one(int n){
        int ans = 0;
        while(n>0){
            int m = n % 10 ;
            ans = ans + m;
            n = n / 10;
        }
        return ans;
    }

    int addDigits(int num) {
        int ans = one(num);
        while(true){
            if(ans < 10){
                return ans;
            }
            else
                ans = one(ans);
        }
        return ans;
    }
};
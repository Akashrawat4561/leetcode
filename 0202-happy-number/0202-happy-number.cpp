class Solution {
public:
    int one(int n){
        int ans = 0;
        while(n>0){
            int m = n%10;
            ans = ans + m * m;
            n = n / 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        if(n==1){
            return true;
        }
        int count = 0;
        int ans = one(n);
        while(true){
            if(ans == 1){
                return true;
            }
            else if(ans != 1 && count < 10){
                ans = one(ans);
                count++;
            }
            else 
                return false;
        }
        return true;
    }
};
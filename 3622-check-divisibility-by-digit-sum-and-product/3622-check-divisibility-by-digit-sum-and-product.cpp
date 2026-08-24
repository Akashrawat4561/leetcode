class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int pro = 1;

        int org = n;

        while(n>0){
            int m = n % 10;
            sum += m;
            pro *= m;
            n = n / 10;
        }
        
        int total = sum + pro;
        
        if((org % total) == 0){
            return true;
        }

        return false;
    }
};
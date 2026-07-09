class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        int sum = 0;
        while(n > 0){
            int m = n % 10;
            if(m != 0){
                x = x * 10 + m;
                sum = sum + m;
            }
            n = n / 10;
        }
        long long ans = 0;
        while(x > 0){
            int m = x % 10;
            ans = ans * 10 + m;
            x = x / 10;
        }
        return ans*sum;
    }
};
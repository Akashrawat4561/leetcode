class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        int first = 1,sec = 2;
        int temp = 0;
        for(int i=2;i<n;i++){
            temp = first + sec;
            first = sec;
            sec = temp;
        }
    return sec;
    }
};
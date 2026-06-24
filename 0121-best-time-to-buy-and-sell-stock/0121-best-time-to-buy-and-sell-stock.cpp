class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minp = INT_MAX;
        int maxp = 0;
        for(int i=0;i<n;i++){
            int price = prices[i];
            if(price < minp){
                minp = price;
            }
            else if(price - minp > maxp){
                maxp = price - minp;
            }
        }
        return maxp;
    }
};
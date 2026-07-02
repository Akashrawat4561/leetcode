class Solution {
public:

    static bool com(int a,int b){
        return a > b;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int>score1(n);
        vector<string>ans(n);

        for(int i=0;i<n;i++){
            score1[i] = score[i];
        }

        sort(score1.begin(),score1.end(),com);
        int idx = 0;
        for(int i=0;i<n;i++){
            idx = find(score1.begin(), score1.end(), score[i]) - score1.begin();
            if(idx > 2){
                ans[i] = to_string(idx + 1);
                idx++;
            }
            else if(score1[idx] == score[i] && idx == 0){
                ans[i] = "Gold Medal";
                idx++;
            }
            else if(score1[idx] == score[i] && idx == 1){
                ans[i] = "Silver Medal";
                idx++;
            }
            else if(score1[idx] == score[i] && idx == 2){
                ans[i] = "Bronze Medal";
                idx++;     
            }
        }
        return ans;
    }
};
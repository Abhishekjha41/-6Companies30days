class Solution {
public:
    int maxProfit(int x, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2,vector<int>(x+1,0)),cur(2,vector<int>(x+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=x;k++){
                    if(j==1){
                        cur[j][k] = max(after[1][k],prices[i]+after[0][k-1]);
                    }
                    if(j==0){
                        cur[j][k] = max(-prices[i]+after[1][k],after[0][k]);
                    }
                }
            }
            after = cur;
        }
        return after[0][x];
    }
};
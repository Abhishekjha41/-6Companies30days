class Solution {
public:
    map<vector<int>,int> dp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(dp.count(needs)!=0) return dp[needs];
        int ans = 0;
        int n = price.size();
        for(int i=0;i<n;i++){
            ans += price[i]*needs[i];
        }

        for(int i=0;i<special.size();i++){
            int isValidOffer = 1;
            for(int j=0;j<n;j++){
                if(special[i][j]>needs[j]){
                    isValidOffer = 0;
                    break;
                }
            }

            if(isValidOffer==1){
                for(int j=0;j<n;j++){
                    needs[j] -= special[i][j];
                }
                int ans2 = 0;
                ans2  = special[i][n] + shoppingOffers(price,special,needs);
                ans = min(ans,ans2);

                for(int j=0;j<n;j++){
                    needs[j] += special[i][j];
                }
            }
        }
        return dp[needs] = ans;
    }
};
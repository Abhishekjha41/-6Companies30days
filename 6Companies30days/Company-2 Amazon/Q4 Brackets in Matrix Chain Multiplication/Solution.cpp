class Solution {
  public:
    pair<string,int> helper(vector<int> arr,int i,int j,vector<vector<pair<string,int>>>& dp){
        if(i==j){
            string st = "";
            st += 'A'+i-1;
            return {st,0};
        }
        if(dp[i][j].second!=-1) return dp[i][j];
        int mini = 1e9;
        string ans = "";
        for(int k=i;k<j;k++){
            auto func1 = helper(arr,i,k,dp);
            auto func2 = helper(arr,k+1,j,dp);
            int steps = arr[i-1]*arr[k]*arr[j] + func1.second + func2.second;
            if(steps< mini){
                ans = "("+func1.first+func2.first+")";
                mini = steps;
            }
        }
        return dp[i][j] = {ans,mini};
    }
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        vector<vector<pair<string,int>>> dp(n,vector<pair<string,int>>(n,{"",-1}));
        pair<string,int> ans = helper(arr,1,n-1,dp);
        return ans.first;
    }
    
};
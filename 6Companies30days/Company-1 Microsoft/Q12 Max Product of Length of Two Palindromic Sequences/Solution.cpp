class Solution {
public:
    int lcs(string a, string b){
        int n = a.length();
        int m = b.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 or j==0)dp[i][j] = 0;
                else if(a[i-1] == b[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int answer(string s){
        string ss = s;
        reverse(ss.begin(), ss.end());
        return lcs(s, ss);
    }
    int maxProduct(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<=(1<<n);i++) {
            string x = "", y = "";
            for(int j=0;j<n;j++){
                if((1<<j)&i) x+=s[j];
                else y+=s[j];
            }
            ans = max(ans, answer(x)*answer(y));
        }
        return ans;
    }
};
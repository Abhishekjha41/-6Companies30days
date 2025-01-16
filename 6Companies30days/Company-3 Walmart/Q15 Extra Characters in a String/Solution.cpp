class Solution {
public:
    vector<int> dp;
    int helper(string s,vector<string>& dict,int idx){
        if(idx>=s.length()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int currlen = 0;
        int minExtra = INT_MAX;
        int poss1 = INT_MAX;
        for(auto word: dict){
            currlen = word.length();
            if(idx+currlen-1>=s.length()) continue;
            
            if(s.substr(idx,currlen)==word){
                minExtra = min(helper(s,dict,idx+currlen),minExtra);
            }
            
        }
        minExtra= min(minExtra,helper(s,dict,idx+1)+1);
        return dp[idx] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        dp = vector(n,-1);
        return helper(s,dictionary,0);
    }
};
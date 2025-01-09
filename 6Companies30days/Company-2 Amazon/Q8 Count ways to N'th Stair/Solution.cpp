class Solution {
public:
    unordered_map<int, unordered_map<int, unordered_map<int,int>>> dp;
    int solve(int k,int idx,int jump,int isLastDownJump){
        if(idx>k+1) return 0;
        if(dp.count(idx) && dp[idx].count(isLastDownJump) && dp[idx][isLastDownJump].count(jump)){
            return dp[idx][isLastDownJump][jump];
        }

        int ans = (idx==k);
        ans += solve(k,idx+pow(2,jump),jump+1,0);
        if(idx!=0 && !isLastDownJump){
            ans += solve(k,idx-1,jump,1);
        }
        return dp[idx][isLastDownJump][jump] = ans;
    }
    int waysToReachStair(int k) {
        return solve(k,1,0,0);
    }
};
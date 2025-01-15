class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1),hash(n,-1);
        int lastidx = -1;
        int maxi = -1;
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int j=0;j<=i-1;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastidx = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastidx]);
        while(hash[lastidx]!=lastidx){
            ans.push_back(nums[hash[lastidx]]);
            lastidx = hash[lastidx];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
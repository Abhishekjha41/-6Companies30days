class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n= s.length() ;
        int ans = 0;
        int cost = 0;
        int j=0, k=0;
        while(k<n) {
            cost = cost+abs(s[k]-t[k]) ;
            if(cost<=maxCost) ans = max(k-j+1,ans) ;
            else{
                while(cost>maxCost && j<=k) {
                    cost = cost - abs(s[j]-t[j]);
                    j++;
                }
                if(cost<=maxCost) ans = max(ans, k-j+1);
            }
            k++;
        }
        return ans;
    }
};
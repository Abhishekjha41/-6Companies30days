class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n,0);
        vector<int> suff(n,0);
        pref[0] = 1;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                pref[i] = pref[i-1]+1;
            }
            else{
                pref[i] = 1;
            }
        }
        suff[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                suff[i] = suff[i+1]+1;
            }
            else{
                suff[i] = 1;
            }
        }
        int ans = 0;
        for(int i=1;i<n-1;i++){
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
                ans = max(ans,pref[i-1]+suff[i+1]+1);
            }
        }
        return ans;
    }
};
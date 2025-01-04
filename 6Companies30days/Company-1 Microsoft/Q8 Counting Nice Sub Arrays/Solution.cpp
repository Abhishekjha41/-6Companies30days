class Solution {
public:
    int helper(vector<int>& nums,int k){
        int ans = 0;
        int odds = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(j<n){
            if(nums[j]%2==1){
                odds++;
            }
            while(odds>k){
                if(nums[i]%2==1) odds--;
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cntksubarr = helper(nums,k);
        int cntk_1subarr = helper(nums,k-1);
        return cntksubarr-cntk_1subarr;
    }
};
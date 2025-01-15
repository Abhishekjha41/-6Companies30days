class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
            ans += (nums[i]*i);
        }
        int prev = ans;
        for(int i=n-1;i>=1;i--){
            ans = max(ans,prev+sum-(n*nums[i]));
            prev = prev+sum-(n*nums[i]);
        }
        return ans;
    }
};
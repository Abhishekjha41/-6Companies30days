class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        unordered_map<int,int> mp; // elem -> idx
        int i=0;
        int j = 0;
        long long currsum = 0;
        while(j<n){
            int lastoccurence = mp.count(nums[j]) ? mp[nums[j]] : -1;
            while(i<=lastoccurence || j-i+1 >k){
                currsum -= nums[i];
                i++;
            }
            currsum += nums[j];
            mp[nums[j]] = j;
            if(j-i+1 == k){
                ans = max(ans,currsum);
            }
            j++;
        }
        return ans;
    }
};
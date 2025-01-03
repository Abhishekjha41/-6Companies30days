class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int medidx = n/2;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(i!=medidx){
                ans += abs(nums[medidx]-nums[i]);
            }
        }
        return ans;
    }
};
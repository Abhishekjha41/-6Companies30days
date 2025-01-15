class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2) return 0;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        int ans =0;
        for(auto [el,fq]: freq){
            if(k==0){
                if(fq>1) ans++;
            }
            else {
                if(freq.find(el+k)!=freq.end()){
                    ans++;
                }
                if(freq.find(el-k)!=freq.end()){
                    ans++;
                }

            }

        }
        return k==0 ? ans: ans/2;
    }
};
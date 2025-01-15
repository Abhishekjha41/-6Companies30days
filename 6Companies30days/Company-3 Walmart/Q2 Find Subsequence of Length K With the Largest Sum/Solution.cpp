class Solution {
public:
    # define P pair<int,int> 
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<P,vector<P>, greater<P>> pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            while(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> indices;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            indices.push_back(it.second);
        }
        sort(indices.begin(),indices.end());
        vector<int> ans(k,0);
        for(int i=0;i<k;i++){
            ans[i] = nums[indices[i]];
        }
        return ans;
    }
};
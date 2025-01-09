class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();
            
            while(!dq.empty() && arr[dq.back()]<arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1) ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};
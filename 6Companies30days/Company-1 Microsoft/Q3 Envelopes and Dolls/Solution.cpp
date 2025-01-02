class Solution {
public:
    // using LIS(dp)with Binary Search
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a,const vector<int>& b){
            return (a[0] < b[0]) || (a[0]==b[0] && a[1]>b[1]);
        });
        vector<int> heights;
        for(auto it: envelopes){
            heights.push_back(it[1]);
        }

        vector<int> lis;
        lis.push_back(heights[0]);
        for(int i=1;i<heights.size();i++){
            if(heights[i] > lis.back()){
                lis.push_back(heights[i]);
            }
            else{
                auto position = lower_bound(lis.begin(),lis.end(),heights[i]);
                *position = heights[i];
            }
        }
        return lis.size();
    }
};
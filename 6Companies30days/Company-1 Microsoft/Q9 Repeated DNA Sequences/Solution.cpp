class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        int n = s.length();
        for(int i=0;i<n-9;i++){
            mp[s.substr(i,10)]++;
        }
        vector<string> ans;
        for(auto p: mp){
            if(p.second>1){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};
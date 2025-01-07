class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> dist(26,vector<int>(26,1e9));
        int n = original.size();
        for(int i=0;i<n;i++){
            dist[original[i]-'a'][changed[i]-'a'] = min(dist[original[i]-'a'][changed[i]-'a'],cost[i]);
        }
        for (int k = 0; k < 26; ++k){
            for (int i = 0; i < 26; ++i){
                for (int j = 0; j < 26; ++j){
                    if (dist[i][k] != 1e9 && dist[k][j] != 1e9 && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        int m = source.size();
        long long ans = 0;
        for(int i=0;i<m;i++){
            if(source[i]!=target[i]){
                if(dist[source[i]-'a'][target[i]-'a']==1e9) return -1;
                ans += dist[source[i]-'a'][target[i]-'a'];
            }

        }
        return ans;

    }
};
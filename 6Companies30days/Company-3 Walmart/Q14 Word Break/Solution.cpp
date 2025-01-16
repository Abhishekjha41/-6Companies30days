class TrieNode{
public:
    bool isword;
    TrieNode* children[26];

    TrieNode(){
        isword = false;
        memset(children,0,sizeof(children));
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for(auto word: wordDict){
            TrieNode* curr = root;
            for(auto ch: word){
                if(curr->children[ch-'a']==NULL) curr->children[ch-'a'] = new TrieNode();
                curr = curr->children[ch-'a'];
            }
            curr->isword = true;
        }

        int n = s.length();
        vector<bool> dp(n);
        for(int i=0;i<n;i++){
            if(i-1==-1 || dp[i-1]){
                TrieNode* curr = root;
                for(int j=i;j<n;j++){
                    char c = s[j];
                    if(curr->children[c-'a']==NULL){
                        break;
                    }
                    curr = curr->children[c-'a'];
                    if(curr->isword){
                        dp[j] = true;
                    }
                }
            }
        }
        return dp[n-1];
    }
};
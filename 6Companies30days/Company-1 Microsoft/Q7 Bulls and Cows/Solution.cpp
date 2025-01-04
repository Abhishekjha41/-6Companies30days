class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int,int> freq;
        int n = secret.length();
        for(int i=0;i<n;i++){
            freq[secret[i]]++;
        }
        int bulls = 0;
        int cows  = 0;
        for(int i=0;i<n;i++){
            if(guess[i]==secret[i]) {
                bulls++;
                freq[guess[i]]--;
                if(freq[guess[i]]==0){
                    freq.erase(guess[i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(guess[i]!=secret[i]){
                if(freq.find(guess[i])!=freq.end() && freq[guess[i]]>0){
                    cows++;
                    freq[guess[i]]--;
                    if(freq[guess[i]]==0) freq.erase(guess[i]);
                }
            }
        }
        string ans = to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;
    }
};

class Solution {
public:
    vector<int>mp = {2,3,5,7,11,13,17,19,23,29};
    int convert(int num){
        int ans = 0;
        for(auto it = mp.begin();it != mp.end();it++){
            if(num%(*it) == 0){
                num /= (*it);
                if(num%(*it) == 0){
                    return -1;
                }
                ans = 2*ans + 1;
            }
            else{
                ans = 2*ans;
            }
        }
        return ans;
    }
    const int mod = 1e9 + 7;
    int squareFreeSubsets(vector<int>& nums) {
        vector<int>count(1024,0);
        count[0] = 1;
        int temp = convert(nums[0]);
        if(temp != -1){count[temp]++;}
        for(int i = 1;i < nums.size();i++){
            int temp = convert(nums[i]);
            cout << temp << endl;
            if(temp != -1){
                for(int j = 0;j < 1024;j++){
                    if((temp & j) == 0){
                        count[(temp | j)] = (count[(temp | j)] + count[j])%mod;
                    }
                }
            }
        }
        int ans = 0;
        for(int j = 0;j < 1024;j++){
            ans = (ans + count[j])%mod;
        }
        if(ans == 0){return mod - 1;}
        return ans - 1;
    }
};
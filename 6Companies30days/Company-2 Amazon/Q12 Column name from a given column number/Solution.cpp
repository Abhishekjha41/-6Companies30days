class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        int val = columnNumber;
        while(val>0){
            if(val>26){
                int rem = (val-1)%26;
                val = (val-1)/26;
                string temp = "";
                temp += ('A'+rem);
                temp += ans;
                ans = temp;
            }
            else if(val<=26){
                string temp = "";
                temp += ('A'+val-1);
                temp += ans;
                ans = temp;
                val = 0;
            }
        }
        return ans;
    }
};
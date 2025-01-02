class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> frnds(n);
        for(int i=0;i<n;i++){
            frnds[i] = i+1;
        }
        int i = 0;
        while(n>1){
            i = (i+k-1)%n;
            frnds.erase(frnds.begin()+i);
            n--;
        }
        return frnds[0];
    }
};
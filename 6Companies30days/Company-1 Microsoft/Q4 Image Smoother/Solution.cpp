class Solution {
public:
    bool isValid(int r,int c,int m,int n){
        if(r>=0 && r<m && c>=0 && c<n) return true;
        return false;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans = img;
        int r[] = {0,-1,-1,-1,0,1,1,1};
        int c[] = {-1,-1,0,1,1,1,0,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cnt = 1;
                int sum = img[i][j];
                for(int k=0;k<8;k++){
                    if(isValid(i+r[k],j+c[k],m,n)){
                        sum += img[i+r[k]][j+c[k]];
                        cnt++;
                    }
                }
                ans[i][j] = (sum/cnt);
            }
        }
        return ans;
    }
};
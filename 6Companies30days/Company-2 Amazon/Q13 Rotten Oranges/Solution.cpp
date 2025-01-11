class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        int time = 0;
        while(!q.empty()){
            int q_sz = q.size();
            int flag = 0;
            while(q_sz>0){
                auto [r,c] = q.front();
                q.pop();
                if(r>0 && grid[r-1][c]==1){
                    grid[r-1][c] = 2;
                    q.push({r-1,c});
                    flag = 1;
                }
                if(r<grid.size()-1 && grid[r+1][c]==1){
                    grid[r+1][c] = 2;
                    q.push({r+1,c});
                    flag = 1;
                }
                if(c>0 && grid[r][c-1]==1){
                    grid[r][c-1] = 2;
                    q.push({r,c-1});
                    flag = 1;
                }
                if(c<grid[0].size()-1 && grid[r][c+1]==1){
                    grid[r][c+1] = 2;
                    q.push({r,c+1});
                    flag = 1;
                }
                q_sz--;
            }
            if(flag == 1){
                time++;
            }
            
        }
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    cnt += 1;
                }
            }
        }
        if(cnt>=1) return -1;
        return time;
    }
};
class Solution {
public:
    bool isValidElem(vector<vector<char>>& board,char el,int r,int c){
        bool col  = true,row = true,box = true;
        for(int i=0;i<9;i++){
            if(i!=c && board[r][i]==el){
                row = false;
                break;
            }
            if(i!=r && board[i][c]==el){
                col = false;
                break;
            }
            int bi = (r/3)*3 + (i/3), bj = (c/3)*3 + (i%3);
            if((bi!=r || bj!=c) && board[bi][bj]==el){
                    box = false;
                    break;
                }
        }
        return (row && col && box);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool valid = true;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    valid = valid && isValidElem(board,board[i][j],i,j);
                }
            }
        }
        return valid;
    }
};
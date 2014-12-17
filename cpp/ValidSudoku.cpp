class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool grid[3][3][9];
        bool row[9][9];
        bool col[9][9];
        memset(grid,0,sizeof(grid));
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]=='.') {
                    continue;
                }
                int number = board[i][j]-'0';
                if(grid[i/3][j/3][number]) {
                    return false;
                }
                grid[i/3][j/3][number] = true;
                if(row[i][number]){
                    return false;
                }
                row[i][number] = true;
                if(col[j][number]){
                    return false;
                }
                col[j][number] = true;
            }
        }
        return true;
    }
};

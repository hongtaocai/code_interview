class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        bool grid[3][3][9];
        bool row[9][9];
        bool col[9][9];
        memset(grid,0,sizeof(grid));
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        fillInDefaultNumbers(board, grid, row, col);
        helper(board, grid, row, col, 0);
    }
    
    void fillInDefaultNumbers(vector<vector<char> > &board, 
        bool grid[3][3][9],
        bool row[9][9],
        bool col[9][9]) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]!='.') {
                    int number = board[i][j]-'0';
                    grid[i/3][j/3][number] = true;
                    row[i][number]=true;
                    col[j][number]=true;
                }
            }
        }
    }
    
    bool helper(vector<vector<char> > &board, 
        bool grid[3][3][9],
        bool row[9][9],
        bool col[9][9],
        int a) {
        if(a==81){
            return true;
        }
        int i = a/9;
        int j = a%9;
        if(board[i][j]!='.') {
            if(helper(board, grid, row, col, a+1)) {
                return true;
            }
        } else {
            for(int number =1; number <=9;number++) {
                if(grid[i/3][j/3][number] || row[i][number] || col[j][number]) {
                    continue;
                }
                grid[i/3][j/3][number] = true;
                row[i][number]=true;
                col[j][number]=true;
                board[i][j] = (char)('0'+ number);
                if(helper(board, grid, row, col, a+1)){
                    return true;
                }
                board[i][j] = '.';
                grid[i/3][j/3][number] = false;
                row[i][number]=false;
                col[j][number]=false;
            }
            return false;
        }
    }
};

class Solution {
public:
    int totalNQueens(int n) {
        return solveNQueens(n).size();
    }
    
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > solutions;
        vector<string> board(n);
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                board[i] = board[i] + ".";
            }
        }
        solveNQueensOnRow(n, 0, solutions, board);
        return solutions;
    }
    
    void solveNQueensOnRow(int n, int row, vector<vector<string> >& solutions, vector<string>& board) {
        if(row == n) {
            vector<string> sol(board.begin(), board.end());
            solutions.push_back(sol);
            return;
        }
        for(int i=0;i<n;i++) {
            board[row][i] = 'Q';
            if(checkVertical(n, row, i, board) && checkDiagnal(n, row, i, board)) {
                solveNQueensOnRow(n, row+1, solutions, board);
            }
            board[row][i] = '.';
        }
    }
    
    bool checkVertical(int n, int row, int col, const vector<string>& board) {
        for(int i=0;i<row;i++) {
            if(board[i][col]=='Q') {
                return false;
            }
        }
        return true;
    }
    
    bool checkDiagnal(int n, int row, int col, const vector<string>& board) {
        for(int i=0;i<row;i++) {
            int j = row + col -i;
            if(j>=0 && j<n && board[i][j] == 'Q') {
                return false;
            }
            j = i - row + col;
            if(j>=0 && j<n && board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};

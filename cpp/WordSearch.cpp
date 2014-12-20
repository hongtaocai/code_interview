class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size();
        if(m==0) return false;
        int n = board[0].size();
        if(n==0) return false;
        if(word.length()==0) return false;
        vector<bool> visited(m*n, false);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j]==word[0] && exist(board, word, i, j, visited, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char> > &board,string& word, int startx, int starty, vector<bool> &visited, int k) {
        int m = board.size();
        int n = board[0].size();
        if(k==word.length()-1) {
            return true;
        }
        visited[startx*n+starty] = true;
        int cellnew[8] = {startx+1, starty, startx, starty+1, startx-1, starty, startx, starty-1};
        for(int i=0;i<4;i++) {
            if(cellnew[2*i] < 0 
                || cellnew[2*i]>= m 
                || cellnew[2*i+1] < 0 
                || cellnew[2*i+1]>= n
                || visited[cellnew[2*i]*n+cellnew[2*i+1]]
                || board[cellnew[2*i]][cellnew[2*i+1]] != word[k+1] ) {
                continue;
            }
            if(exist(board, word, cellnew[2*i], cellnew[2*i+1],visited, k+1)) {
                return true;
            }
        }
        visited[startx*n+starty] = false;
        return false;
    }
};

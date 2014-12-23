class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();
        if(n==0) return;
        for(int i=0;i<m;i++) {
            flip(board, i, 0);
            flip(board, i, n-1);
        }
        for(int i=1;i<=n-1;i++) {
            flip(board, 0, i);
            flip(board, m-1, i);
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j]=='O') {
                    board[i][j]='X';
                } else if(board[i][j]=='Z') {
                    board[i][j]='O';
                }
            }
        }
    }
    
    void flip(vector<vector<char>>& board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        
        queue<pair<int, int>> q;
        if(board[x][y] == 'O') {
            q.push(pair<int,int>(x,y));
        }
        while(!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            x = top.first;
            y = top.second;
            if(x<0 || x>= m || y<0 || y>=n || board[x][y] != 'O') {
                continue;
            }
            
            board[x][y] = 'Z';
            if(x+1<m)
                q.push(pair<int,int>(x+1,y));
            if(y+1<n)
                q.push(pair<int,int>(x,y+1));
            if(x-1>=0)
                q.push(pair<int,int>(x-1,y));
            if(y-1>=0)
                q.push(pair<int,int>(x,y-1));
        }
    }
};

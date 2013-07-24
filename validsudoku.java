public class Solution {
    
    char[][] board;
    
    public boolean isValidSudoku(char[][] board) {
        // Start typing your Java solution below
        // DO NOT write main() function
        this.board = board;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int number = board[i][j]-'0';
                    board[i][j] = '.';
                    if(!check(i,j,number)){
                        return false;
                    }
                    board[i][j] = (char)(number+'0');
                }
            }
        }
        return true;
    }

    private boolean check(int x, int y, int number){
        char target = (char) (number+'0');
        for(int i=0;i<9;i++){
            if(board[x][i]==target){
                return false;
            }
            if(board[i][y]==target){
                return false;
            }
        }
        for(int i=(x/3)*3;i<=(x/3)*3+2;i++){
            for(int j=(y/3)*3;j<=(y/3)*3+2;j++){
                if(board[i][j]==target){
                    return false;
                }
            }
        }
        return true;
    }

    
}
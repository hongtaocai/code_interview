public class Solution {
    
    char [][] board;
    boolean flag;
    
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
    
    public void solveSudoku(int x, int y, int number){
        if(number==0){
            flag = true;
            return;
        }
        if(!flag){
            int i=0;
            int j=0;
            
            loop1: for(i=x;i<9;i++){
                for(j=0;j<9;j++){
                    if(i==x && j<y ) continue;
                    if(board[i][j]=='.'){
                        break loop1;
                    }
                } 
            }
            for(int k=1;k<=9;k++){
                if(check(i,j,k) && !flag){
                    board[i][j]=(char)('0'+k);
                    solveSudoku(i,j+1,number-1);
                    if(!flag){
                        board[i][j]='.';
                    }
                }
            }
        }
    }
    
    public void solveSudoku(char[][] board) {
        // Start typing your Java solution below
        // DO NOT write main() function
        this.board = board;
        flag = false;
        int sum = 0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    sum++;
                }
            }
        }
        solveSudoku(0,0,sum);
    }
}
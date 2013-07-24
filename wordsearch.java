public class Solution {
    
    class Point{
        int x;
        int y;
        Point(int x, int y){
            this.x = x;
            this.y = y;
        }
        boolean check(int xx, int yy){
            return  x<xx && x>=0 && y<yy && y>=0 && !mark[x][y] ;
        }
        Point add(Point p){
            return new Point(this.x+p.x,this.y+p.y);
        }
    }
    
    boolean mark[][];
    
    Point pp[] = new Point[4];
    

    
    boolean find(char[][] board, String word, Point start){
        if(word.length()==0) return true;
        if(word.charAt(0)!= board[start.x][start.y]) return false;
        if(word.length()==1) return true;
        
        for(int i=0;i<4;i++){
            Point newp = start.add(pp[i]);
            if(newp.check(board.length, board[0].length)){
                mark[start.x][start.y] = true;
                if(find(board,word.substring(1),newp)){
                    return true;
                }
                mark[start.x][start.y] = false;
            }
        }
        return false;
    }
    
    
    public boolean exist(char[][] board, String word) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int x = board.length;
        int y = board[0].length;
        if(word.length()==0) return true;
        ArrayList<Point> startSet = new ArrayList<Point>();
        
        pp[0] = new Point(1,0);
        pp[1] = new Point(0,1);
        pp[2] = new Point(-1,0);
        pp[3] = new Point(0,-1);
        
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(board[i][j]==word.charAt(0)){
                    startSet.add(new Point(i,j));
                }
            }
        }
        
        for(Point p : startSet){
            mark = new boolean[x][y];
            if(find(board,word,p)){
                return true;
            }
        }
        
        return false;
    
    }
    
}
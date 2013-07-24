public class Solution {
    public String convert(String s, int nRows) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(nRows==1) return s;
        ArrayList<ArrayList<Character>> al = new ArrayList<ArrayList<Character>>();
        for(int i=0;i<nRows;i++){
            al.add(new ArrayList<Character>());
        }
        int width = nRows;
        int j=0;
        int i=0;
        int dir = -1;
        int up = 1;
        int start = 0;
        while(j<s.length()){
            if(up==1 || nRows<=2 ){
                for(i=0;i<width && j+i<s.length() ;i++){
                    al.get(i+start).add(s.charAt(j+i));   
                }
                up = 0;
            }else{
                for(i=0;i<width && j+i<s.length() ;i++){
                    al.get(width-1-i+start).add(s.charAt(j+i));   
                }
                up = 1;
            }
            
            j+= width;
            
            if(nRows>2){
                if(width==1 || width==2){
                    dir=-1*dir;
                }
                else if(width==nRows || width==nRows-1){
                    dir=-1*dir;
                }
                width -= dir*2;
                start += dir*1;
            }
        }
        StringBuilder ans = new StringBuilder("");
        for( i=0;i<nRows;i++){
            for( j=0;j<al.get(i).size();j++){
                ans.append(al.get(i).get(j));
            }
        }
        return ans.toString();
    }
}

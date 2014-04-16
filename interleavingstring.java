public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if(s3.length()!=s1.length()+s2.length()){
            return false;
        }
        
        boolean ok[][] = new boolean[s1.length()+1][s2.length()+1];
        ok[0][0]=true;
        for(int i=1;i<s1.length()+1;i++){
            ok[i][0] = ok[i-1][0] && s1.charAt(i-1)==s3.charAt(i-1);
        }
        for(int i=1;i<s2.length()+1;i++){
            ok[0][i] = ok[0][i-1] && s2.charAt(i-1)==s3.charAt(i-1);
        }
        for(int i=1;i<s1.length()+1;i++){
            for(int j=1;j<s2.length()+1;j++){
                ok[i][j] = ok[i-1][j] && s1.charAt(i-1) == s3.charAt(i+j-1);
                ok[i][j] |= ok[i][j-1] && s2.charAt(j-1) == s3.charAt(j+i-1);
            }
        }
        return ok[s1.length()][s2.length()];
    }
}

/**
 * A better solution with O(min(m,n)) space complexity
 * 
public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if(s3.length()!=s1.length()+s2.length()){
            return false;
        }

        if(s1.length()>s2.length()){
            String tmp = s1;
            s1 = s2;
            s2 = tmp;
        }
        
        boolean ok[] = new boolean[s2.length()+1];
        boolean next[] = new boolean[s2.length()+1];
        ok[0]=true;
        // for(int i=1;i<s1.length()+1;i++){
        //     ok[i][0] = ok[i-1][0] && s1.charAt(i-1)==s3.charAt(i-1);
        // }
        for(int i=1;i<s2.length()+1;i++){
            ok[i] = ok[i-1] && s2.charAt(i-1)==s3.charAt(i-1);
        }
        for(int i=1;i<s1.length()+1;i++){
            next[0] = ok[0] && s1.charAt(i-1)==s3.charAt(i-1);
            for(int j=1;j<s2.length()+1;j++){
                next[j] = ok[j] && s1.charAt(i-1) == s3.charAt(i+j-1);
                next[j] |= next[j-1] && s2.charAt(j-1) == s3.charAt(j+i-1);
            }
            boolean tmp[] = ok;
            ok = next;
            next = tmp;
        }
        return ok[s2.length()];
    }
}

*/

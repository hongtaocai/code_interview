public class Solution {
    public String minWindow(String S, String T) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int start = 0;
        int end = 0;
        int n =0;
        
        int min = Integer.MAX_VALUE;
        int minstart = 0;
        int minend = 0;
        HashSet<Character> hs = new HashSet<Character>();
        int count[] = new int[300];
        int sta[] = new int[300];
        for(int i=0;i<T.length();i++){
            hs.add(T.charAt(i));
            sta[T.charAt(i)+0]++;
        }
        int target = hs.size();
        boolean found = false;
        while(end<S.length()){
            while(n<target && end < S.length()){
                if(!hs.contains(S.charAt(end))){
                    end++;
                }else{
                    count[S.charAt(end)+0]++;
                    if(count[S.charAt(end)+0]==sta[S.charAt(end)+0]){
                        n++;
                    }
                    end++;
                }
            }
            if(min>end+1-start && n==target){
                found = true;
                min = end+1-start;
                minend = end;
                minstart = start;
            }
            
            while(n==target && start<=end){
                if(!hs.contains(S.charAt(start))){
                    start++;
                }else{
                    if(count[S.charAt(start)+0]==sta[S.charAt(start)+0]){
                        n--;
                    }
                    count[S.charAt(start)+0]--;
                    start++;
                }
            }
            if(min>end+2-start){
                min = end+2-start;
                minend = end;
                minstart = start-1;
            }
        }
        if(!found){
            return "";
        }
        return S.substring(minstart,minend);
    }
}
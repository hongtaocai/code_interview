public class Solution {
    public int lengthOfLongestSubstring(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(s.length()==0){
            return 0;
        }
        int max =1;
        int map[] = new int[26];
        for(int i=0;i<26;i++){
            map[i]=-1;
        }
        int start = 0;
        int end = 1;
        map[s.charAt(start)-'a']=start;
        while(true){
            if(end==s.length()){
                break;
            }
            if(map[s.charAt(end)-'a']==-1){
                map[s.charAt(end)-'a']=end;
                end++;
                if(end-start>max){
                    max = end-start;
                }
            }else{
                int t = map[s.charAt(end)-'a'];
                for(int i=start;i<=t;i++){
                    map[s.charAt(i)-'a']=-1;
                }
                start = t+1;
                map[s.charAt(end)-'a']=end;
                end++;
            }
        }

        return max;
    }
}
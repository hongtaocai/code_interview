public class Solution {
    HashMap<String, Integer> hm = new HashMap<String,Integer>();
    HashMap<String, Integer> ca = new HashMap<String,Integer>();
    
    public ArrayList<Integer> findSubstring(String S, String[] L) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<Integer> ans = new ArrayList<Integer>();
        
        if(L.length==0) return ans;
        
        hm.clear();
        
        for(int i=0;i<L.length;i++){
            if(hm.keySet().contains(L[i])){
                hm.put(L[i],hm.get(L[i])+1);
            }
            else{
                hm.put(L[i],1);
            }
        }
        
        boolean ok[] = new boolean[S.length()];
        
        for(int i=0;i<=S.length()-L[0].length();i++){
            if(hm.keySet().contains(S.substring(i,i+L[0].length()))){
                ok[i]=true;
            }
        }
        boolean flag = true;
        for(int i=0;i<=S.length()-L.length*L[0].length();i++){
            flag = true;
            for(int j=0;j<L.length ;j++){
                if(!ok[i+j*L[0].length()]){
                    flag = false;
                    break;
                }   
            }
            if(flag){
                ca.clear();
                for(int j=0;j<L.length;j++){
                    String tmp = S.substring(i+j*L[0].length(),i+j*L[0].length()+L[0].length());
                    int res = 1;
                    if(ca.keySet().contains(tmp)){
                        res = ca.get(tmp)+1;
                        ca.put(tmp,res);
                    }
                    else{
                        ca.put(tmp,1);
                    }
                    if(res>hm.get(tmp)){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                ans.add(i);
            }
        }
        return ans;
    }
}
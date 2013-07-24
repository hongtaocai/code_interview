public class Solution {
    
    
    
    public String simplifyPath(String path) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(path.length()==1) return path;
        path = path.replaceAll("/$","");
        path = path.replaceAll("/+","/");
        if(path.length()==1) return path;
        Stack<String> s = new Stack<String>();
        while(path.length()!=0){
            int index = path.indexOf('/');
            if(index==-1) index = path.length();
            if(index==0) {
                path = path.substring(1);
                continue;
            }
            String tmp = path.substring(0,index);
            if(index!=path.length()){
                path = path.substring(index+1);
            }else{
                path = "";
            }
            
            if(tmp.equals(".")){
                
            }else if(tmp.equals("..")){
                if(!s.empty()){
                    s.pop();
                }
            }else{
                s.push(tmp);
            }
        }
        String ans = "";
        while(!s.empty()){
            ans = "/" + s.pop() + ans;
        }
        if(ans.length()==0) ans = "/";
        return ans;
        
    }
}
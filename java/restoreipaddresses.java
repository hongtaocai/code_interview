public class Solution {
    
    public boolean ok(String s, int start, int end){
        String tmp =  s.substring(start,end);
        if(tmp.length()>3){
            return false;   
        }else if(tmp.length()==0){
            return false;
        }else if(tmp.length()==1){
            return true;
        }else if(tmp.length()==2){
            return tmp.compareTo("10")>=0 && tmp.compareTo("99")<=0 ;
        }else{
            return tmp.compareTo("100")>=0 && tmp.compareTo("255")<=0;
        }
    }
    
    public ArrayList<String> restoreIpAddresses(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int i1=0;
        int i2=0;
        int i3=0;
        ArrayList<String> al = new ArrayList<String>();
        if(s.length()>3*4) return al;
        for(i1=0;i1<s.length();i1++){
            if(i1>3) continue;
            if(!ok(s,0,i1)) continue;
            for(i2=i1+1;i2<s.length();i2++){
                if(i2-i1>3) continue;
                if(!ok(s,i1,i2)) continue;
                for(i3=i2+1;i3<s.length();i3++){
                    if(i3-i2>3) continue;
                    if(s.length()-i3>3) continue;
                    if(!ok(s,i2,i3)) continue;
                    if(!ok(s,i3,s.length())) continue;
                    StringBuilder sb = new StringBuilder("");
                    sb.append(s.substring(0,i1));
                    sb.append(".");
                    sb.append(s.substring(i1,i2));
                    sb.append(".");
                    sb.append(s.substring(i2,i3));
                    sb.append(".");
                    sb.append(s.substring(i3,s.length()));
                    al.add(sb.toString());
                }
            }
        }
        return al;
        
    }
}
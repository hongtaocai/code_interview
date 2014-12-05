public class Solution {
    public String multiply(String num1, String num2) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(num1.equals("0") || num2.equals("0")){
            return "0";
        }
        
        int res[] = new int[num1.length()+num2.length()];
        int l3 = num1.length()+num2.length()-1;
        int l2 = num2.length()-1;
        int l1 = num1.length()-1;
        for(int i=0;i<num1.length();i++){
            for(int j=0;j<num2.length();j++){
                res[l3-i-j] += (num1.charAt(l1-i)-'0')*(num2.charAt(l2-j)-'0');
            }
        }
        for(int i=0;i<l3;i++){
            res[l3-i-1] += res[l3-i]/10;
            res[l3-i] = res[l3-i]%10;
        }
        int ii=0;
        while(res[ii]==0) ii++;
        StringBuilder sb = new StringBuilder("");
        for(;ii<=l3;ii++){
            sb.append((char)(res[ii]+'0'));
        }
        return sb.toString();
    }
}
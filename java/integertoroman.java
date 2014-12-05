public class Solution {
    public String intToRoman(int num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        StringBuilder ans = new StringBuilder("");
        char a[][] ={ {'I','V','X'}, {'X','L','C'}, {'C','D','M'}, {'M','M','M'}};
        int threshold = 1000;
        for(int i=3;i>=0;i--){
            if(num>=threshold){
                int k = num/threshold;
                num -= k*threshold;
                if(k==0){
                    
                }
                else if(k==9){
                    ans.append(a[i][0]);
                    ans.append(a[i][2]);
                }else if(k<=3){
                    for(int j=0;j<k;j++){
                        ans.append(a[i][0]);
                    }
                }else if(k==4){
                    ans.append(a[i][0]);
                    ans.append(a[i][1]);
                }else if(k<=8){
                    ans.append(a[i][1]);
                    for(int j=0;j<k-5;j++){
                        ans.append(a[i][0]);
                    }
                }
            }
            threshold /=10;
        }
        return ans.toString();
    }
}
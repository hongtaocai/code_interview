public class Solution {
    public int[] plusOne(int[] digits) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int carry = 1;
        for(int i=digits.length-1;i>=0;i--){
            if(carry==0) return digits;
            digits[i]+=carry;
            carry = (digits[i])>9 ? 1:0;
            digits[i]-=10*carry;
        }
        if(carry==1){
            int s[] = new int[digits.length+1];
            s[0] = 1;
            return s;
        }else{
            return digits;
        }
    }
}
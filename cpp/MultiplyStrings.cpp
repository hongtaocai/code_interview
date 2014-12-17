class Solution {
public:
    string multiply(string num1, string num2) {
        int* product = new int[num1.length()+num2.length()];
        memset(product, 0, 4*(num1.length()+num2.length()));
        for(int i=0;i<num1.length();i++) {
            for(int j=0;j<num2.length();j++) {
                int digit1 = num1[num1.length()-1-i]-'0';
                int digit2 = num2[num2.length()-1-j]-'0';
                product[i+j] += digit1*digit2;
            }
        }
        int carry = 0;
        for(int i=0;i<num1.length()+num2.length();i++) {
            int tmp = (product[i]+carry);
            product[i] = tmp%10;
            carry = tmp/10;
        }
        string res = "";
        for(int i=0;i<num1.length()+num2.length();i++) {
            res += char('0' + product[num1.length()+num2.length()-1-i]);
        }
        int i=0;
        for(i=0;i<res.length();i++) {
            if(res[i]!='0') {
                break;
            }
        }
        if(i==res.length()) {
            return "0";
        } 
        return res.substr(i, res.length()-i); 
    }
};

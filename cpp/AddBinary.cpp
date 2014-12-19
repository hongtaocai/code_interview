class Solution {
public:
    string addBinary(string a, string b) {
        int lenA = (int)a.length();
        int lenB = (int)b.length();
        int i = lenA-1;
        int j = lenB-1;
        int carry = 0;
        int sum = 0;
        string res = "";
        while(j>=0 || i>=0) {
            int ai = (i>=0)? (a[i]-'0'):0;
            int bj = (j>=0)? (b[j]-'0'):0;
            sum = (ai+bj+carry);
            res += char(sum%2 + '0');
            carry = sum/2;
            i--;
            j--;
        }
        if(carry==1) {
            res.append("1");
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

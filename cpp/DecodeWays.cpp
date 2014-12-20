class Solution {
public:
    int numDecodings(string s) {
        int n = (int)s.length();
        if(n==0) {
            return 0;
        }
        int f1 = (s[0]=='0')? 0:1;
        if(n==1) {
            return f1;
        }
        int twoC = stoi(s.substr(0,2));
        int f2 = (twoC<=26 && twoC>=10)? 1:0;
        f2 = (s[0]!='0' && s[1]!='0')? (f2+1): f2;
        if(n==2) {
            return f2;
        }
        int f3 = 0;
        for(int i=2;i<s.length();i++) {
            twoC = stoi(s.substr(i-1,2));
            f3 = (twoC<=26 && twoC>=10)? f1: 0;
            f3 = (s[i]!='0')? (f3+f2): f3;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        string sNew = "";
        for(int i=0;i<s.length();i++) {
            if(s[i]>='A'&&s[i]<='Z') {
                sNew.append(1, char(s[i]-'A'+'a'));
            } else if(s[i]>='a'&&s[i]<='z' || s[i]>='0'&&s[i]<='9') {
                sNew.append(1, s[i]);
            } 
        }
        int i=0;
        int j=sNew.length()-1;
        for(;i<j;i++,j--) {
            if(sNew[i]!=sNew[j]) {
                return false;
            }
        }
        return true;
    }
};

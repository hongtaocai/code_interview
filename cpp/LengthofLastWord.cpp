class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int n = (int)strlen(s);
        if(n==0) {
            return 0;
        }
        int i=n-1;
        while(i>=0 && s[i]==' ') {
            i--;
        }
        int count = 0;
        while(i>=0 && s[i]!=' ') {
            count ++;
            i--;
        }
        return count;
    }
};

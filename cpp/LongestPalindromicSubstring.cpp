class Solution {
public:
    string longestPalindrome(string s) {
        string s1 = "#";
        for(int i=0;i<s.length();i++) {
            s1 += s[i];
            s1 += '#';
        }
        string t = longestPalindromeHelper(s1);
        string res = "";
        for(int i=0;i<t.length();i++) {
            if(t[i]!='#') {
                res += t[i];
            }
        }
        return res;
    }
    
    string longestPalindromeHelper(string s) {
        int center = 0;
        int right = 0;
        int n = s.length();
        int* P = new int[n];
        for(int i=0;i<n;i++) {
            P[i] = 0;
        }
        int max = 0;
        int maxP = 0;
        for(int i=0; i<n; i++) {
            if ( i <= right ) {
                P[i] = (P[center*2-i] > right - i) ? (right - i): P[center*2-i];
            }
            while(i-P[i]-1 >=0
                  && i+P[i]+1 <= s.length()-1
                  && s[i-P[i]-1] == s[i+P[i]+1]) {
                P[i]++;
            }
            if(P[i]>maxP) {
                maxP = P[i];
                max = i;
            }
            if(i+P[i]>right) {
                right = i+P[i];
                center = i;
            }
        }
        delete[] P;
        return s.substr(max-maxP, 2*maxP+1);
    }
};

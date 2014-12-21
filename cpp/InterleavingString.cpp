class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) {
            return false;
        }
        if(s1.length() < s2.length()) {
            string tmp = s1;
            s1 = s2;
            s2 = tmp;
        }
        int m = (int)s2.length();
        vector<bool> isI(m+1);
        for(int j=0;j<m+1;j++) {
            if(j==0) {
                isI[j] = true;
            } else {
                isI[j] = (isI[j-1] && (s2[j-1] == s3[j-1]));
            }
        }
        for(int i=1;i<s1.length()+1;i++) {
            for(int j=0;j<m+1;j++) {
                int i3 = i+j-1;
                int i1 = i-1;
                int i2 = j-1;
                if(j==0) {
                    isI[j] = (s1[i1]==s3[i3] && isI[j]);
                } else {
                    isI[j] = (s1[i1]==s3[i3] && isI[j]) || (s2[i2]==s3[i3] && isI[j-1]);
                }
            }
        }
        return isI[m];
    }
};

class Solution {
public:
    int numDistinct(string S, string T) {
        int* num = new int[T.length()+1];
        for(int j=0;j<=(int)T.length();j++) {
            num[j] = 0;
        }
        num[0] = 1;
        for(int i=1;i<=(int)S.length();i++) {
            for(int j=(int)T.length();j>=1;j--) {
                if(S[i-1]==T[j-1]) {
                    num[j] += num[j-1]; // S...k  k  
                } 
            }
        }
        return num[T.length()];
    }
};

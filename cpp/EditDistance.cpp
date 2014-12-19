class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = (int)word1.length()+1;
        int n2 = (int)word2.length()+1;
        int** d = new int*[n1];
        for(int i=0;i<n1;i++) {
            d[i] = new int[n2];
            for(int j=0;j<n2;j++) {
                d[i][j] = 0;
            }
        }
        for(int i=0;i<n1;i++) {
            d[i][0] = i;
        }
        for(int j=0;j<n2;j++) {
            d[0][j] = j;
        }
        for(int i=1;i<n1;i++) {
            for(int j=1;j<n2;j++) {
                if(word1[i-1] == word2[j-1]) {
                    d[i][j] = d[i-1][j-1];
                } else {
                    d[i][j] = min(d[i-1][j-1] + 1, d[i][j-1] +1);
                    d[i][j] = min(d[i][j], d[i-1][j]+1);
                }
            }
        }
        int res = d[n1-1][n2-1];
        for(int i=0;i<n1;i++) {
            delete[] d[i];
        }
        delete[] d;
        return res;
    }
};

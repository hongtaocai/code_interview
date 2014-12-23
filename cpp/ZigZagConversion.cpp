class Solution {
public:
    string convert(string s, int nRows) {
        // 0, 2nRows-2, 4nRows-4....
        // 1, 2nRows-3, 2nRows-1, 4nRows-5, 4nRows-3
        // ...
        // nRows-1, 
        if(nRows==1) return s;
        int n = (int)s.length();
        string res(n, '0');
        
        int t = 0;
        for(int i=0;i<nRows;i++) {
            int j=0;
            while(t<n) {
                if(i==0) {  
                    if(j*(2*nRows-2)<=n-1) {
                        res[t] = s[j*(2*nRows-2)];
                        t++;
                    } else {
                        break;
                    }
                } else if(i==nRows-1) {
                    if(j*(2*nRows-2) + (nRows-1) <= n-1) {
                        res[t] = s[j*(2*nRows-2) + (nRows-1)];
                        t++;
                    } else {
                        break;
                    }
                } else {
                    if(j*(2*nRows-2) + i <= n-1) {
                        res[t] = s[j*(2*nRows-2) + i];
                        t++;
                    } else {
                        break;
                    }
                    if((j+1)*(2*nRows-2)-i <= n-1) {
                        res[t] =  s[(j+1)*(2*nRows-2)-i];
                        t++;
                    } else {
                        break;
                    }
                }
                j++;
            }
        }
        return res;
    }
};

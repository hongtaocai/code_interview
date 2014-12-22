class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> t(rowIndex+1);
        t[0] = 1;
        for(int i=1;i<rowIndex+1;i++) {
            for(int j=i;j>=0;j--) {
                if(j==0) {
                    t[j] = t[j];
                } else {
                    t[j] = t[j]+t[j-1];
                } 
            }
        }
        return t;
    }
};

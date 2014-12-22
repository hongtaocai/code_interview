class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        vector<int> t;
        if(numRows==0) {
            return res;
        }
        t.push_back(1);
        res.push_back(t);
        for(int i=1;i<numRows;i++) {
            t.push_back(0);
            for(int j=i;j>=0;j--) {
                if(j==0) {
                    t[j] = t[j];
                } else {
                    t[j] = t[j]+t[j-1];
                }
            }
            res.push_back(t);
        }
        return res;
    }
};

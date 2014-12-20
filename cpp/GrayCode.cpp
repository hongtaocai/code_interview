class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0) {
            return vector<int>{0};
        }
        if(n==1) {
            return vector<int> {0,1};
        }
        vector<int> v = grayCode(n-1);
        vector<int> v1(v.begin(), v.end());
        reverse(v1.begin(), v1.end());
        int c = (1 << (n-1));
        for(int i=0;i<v1.size();i++) {
            v1[i] = v1[i] + c;
        }
        v.insert(v.end(), v1.begin(), v1.end());
        return v;
    }
};

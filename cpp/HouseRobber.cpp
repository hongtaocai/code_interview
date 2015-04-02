class Solution {
public:
    int rob(vector<int> &num) {
        int n = (int) num.size();
        if(n==0) {
            return 0;
        }
        int m1 = 0; // choose last one
        int m2 = 0; // not choose last one
        m1 = num[0];
        if(n==1) {
            return m1;
        }
        m1 = num[1];
        m2 = num[0];
        if(n==2) {
            return max(m1, m2);
        }
        for(int i=2;i<n;i++) {
            int m1_ = m2+num[i]; // chose last one
            int m2_ = max(m1, m2); // not choose last one
            m1 = m1_;
            m2 = m2_;
        }
        return max(m1, m2);
    }
};

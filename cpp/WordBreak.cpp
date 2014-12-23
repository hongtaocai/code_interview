class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.length();
        if(n==0) return false;
        bool* t = new bool[n+1];
        t[0] = true;
        for(int i=1;i<=n;i++) {
            t[i] = false;
            for(int j=0;j<=i;j++) {
                t[i] |= t[j] && (dict.find(s.substr(j,i-j)) != dict.end());
                if(t[i]) {
                    break;
                }
            }
        }
        return t[n];
    }
};

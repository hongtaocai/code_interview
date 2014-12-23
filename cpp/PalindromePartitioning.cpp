class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = (int)s.length();
        bool* isP = new bool[(n+1)*(n+1)];
        for(int len=1;len<=n;len++) {
            for(int j=0;j+len<=n;j++) {
                if(len==1) {
                    isP[j*(n+1)+(j+len)] = true;
                } else if(len==2) {
                    isP[j*(n+1)+(j+len)] = (s[j]==s[j+1]);
                } else {
                    isP[j*(n+1)+(j+len)] = isP[(j+1)*(n+1)+(j+len-1)] && (s[j] == s[j+len-1]);
                }
            }
        }
        vector<string> curSol;
        vector<vector<string>> solutions;
        helper(s, 0, curSol, solutions, isP, n);
        return solutions;
    }
    
    void helper(const string& s, int start, vector<string>& curSol, vector<vector<string>>& solutions, bool* isP, int n) {
        if(start == n) {
            solutions.push_back(curSol);
            return;
        }
        for(int i=start+1;i<=n;i++) {
            if(isP[start*(n+1)+i]) {
                curSol.push_back(s.substr(start, i-start));
                helper(s, i, curSol, solutions, isP, n);
                curSol.pop_back();
            }
        }
    }
};

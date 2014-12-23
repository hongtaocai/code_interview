ass Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.length();
        if(n==0) return vector<string>();
        bool* t = new bool[n+1];
        vector<vector<int>> back(n+1);
        t[0] = true;
        for(int i=1;i<=n;i++) {
            t[i] = false;
            for(int j=0;j<i;j++) {
                if(t[j] && (dict.find(s.substr(j,i-j)) != dict.end())) {
                    back[i].push_back(j);
                    t[i] = true;
                }
            }
        }
        vector<string> sols;
        vector<int> sol;
        helper(sol, sols, back, n, s, n);
        return sols;
    }
    
    void helper(vector<int>& sol, vector<string>& sols, vector<vector<int>>& back, int n, string& s, int k) {
        if(k==0) {
            sol.push_back(0);
            string res;
            for(int i=sol.size()-1;i>=1;i--) {
                if(i==1) {
                    res += (s.substr(sol[i], sol[i-1]-sol[i]));
                } else {
                    res += (s.substr(sol[i], sol[i-1]-sol[i]) + " ");
                }
            }
            sols.push_back(res);
            sol.pop_back();
        }
        for(int i=0;i<back[k].size();i++) {
            sol.push_back(k);
            helper(sol, sols, back, n, s, back[k][i]);
            sol.pop_back();
        }
    }
};

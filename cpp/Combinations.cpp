class Solution {
public:
    vector<vector<int> >  combine(int n, int k) {
        vector<vector<int> > solutions;
        if(k>n) {
            return solutions;
        }
        vector<int> cur;
        helper(n, 0, cur, solutions, k);
    }
    
    void helper(int n, int lastVisit, vector<int>& cur, vector<vector<int> >& solutions, int sumPick) {
        if(sumPick==0) {
            solutions.push_back(cur);
            return;
        }
        if(sumPick>n-lastVisit) {
            return;
        }
        for(int i=lastVisit+1;i<=n;i++) {
            cur.push_back(i);
            helper(n, i, cur, solutions, sumPick-1);
            cur.pop_back();
        }
    }
};

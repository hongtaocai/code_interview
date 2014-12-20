class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > solutions;
        if(S.size()==0) {
            return solutions;
        }
        sort(S.begin(), S.end());
        vector<int> curIndexes;
        helper(S, 0, curIndexes, solutions);
        return solutions;
    }

    void helper(vector<int> &S, int k, vector<int>& curIndexes, vector<vector<int> >& solutions) {
        if(k==(int)S.size()) {
            vector<int> sol(curIndexes.size());
            for(int i=0;i<(int)curIndexes.size();i++) {
                sol[i] = S[curIndexes[i]];
            }
            solutions.push_back(sol);
            return;
        }
        if(k>0 && S[k]==S[k-1]) {
            if(curIndexes.empty() || curIndexes.back() != k-1) {
                helper(S, k+1, curIndexes, solutions);
            } else {
                helper(S, k+1, curIndexes, solutions);
                curIndexes.push_back(k);
                helper(S, k+1, curIndexes, solutions);
                curIndexes.pop_back();
            }
        } else {
            helper(S, k+1, curIndexes, solutions);
            curIndexes.push_back(k);
            helper(S, k+1, curIndexes, solutions);
            curIndexes.pop_back();
        }
    }
};

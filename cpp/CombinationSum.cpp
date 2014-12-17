class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        if(candidates.size()==0) {
            return vector<vector<int> >();
        }
        sort(candidates.begin(), candidates.end());
        return combinationSum(candidates, (int)candidates.size()-1, target);
    }
    
    vector<vector<int> > combinationSum(vector<int> &sortedCandidates, int end, int target) {
       if(end==-1) {
           if(target==0) {
                vector<int> v;
                vector<vector<int> > res;
                res.push_back(v);
                return res;
           } else {
               return vector<vector<int> >();
           }
       }
       vector<vector<int> > cWithoutLast = combinationSum(sortedCandidates, end-1, target);
       if(target < sortedCandidates[end]) {
           return cWithoutLast;
       }
       target -= sortedCandidates[end];
       vector<vector<int> > cWithLast = combinationSum(sortedCandidates, end, target);
       for(int i=0;i<cWithLast.size();i++) {
           cWithLast[i].push_back(sortedCandidates[end]);
       }
       cWithLast.insert(cWithLast.end(), cWithoutLast.begin(), cWithoutLast.end());
       return cWithLast;
    }
};

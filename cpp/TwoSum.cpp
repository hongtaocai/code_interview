class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        unordered_map<int, int> valToIndex;
        for(int i=0;i<numbers.size(); ++i) {
            valToIndex[numbers[i]] = (i+1);
        }
        for(int i=0;i<numbers.size(); ++i) {
            int t = valToIndex[target-numbers[i]];
            if(t!=0 && t!=i+1) {
                res.push_back(i+1);
                res.push_back(t);
                return res;
            }
        }
        return res;
    }
};

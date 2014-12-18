class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > sortedToString;
        for(auto it=strs.begin(); it!=strs.end(); it++) {
            string copy = *it;
            sort(copy.begin(), copy.end());
            vector<string> v = sortedToString[copy];
            v.push_back(*it);
            sortedToString[copy] = v;
        }
        vector<string> res;
        for(auto it=sortedToString.begin(); it!=sortedToString.end(); it++) {
            if (it->second.size()>1) {
                res.insert(res.end(), it->second.begin(), it->second.end());
            }
        }
        return res;
    }
};

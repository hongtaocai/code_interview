class Solution {
public:
    string d2C[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length() == 0) {
            res.push_back("");
            return res;
        }
        char t = digits[0];
        string cs = d2C[(t-'0')];
        vector<string> letters = letterCombinations(digits.substr(1));
        for(int i=0;i<cs.length();i++) {
            for(int j=0;j<letters.size();j++) {
                res.push_back(cs.substr(i,1) + letters[j]);
            }
        }
        return res;
    }
};

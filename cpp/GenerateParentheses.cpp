class Solution {
public:
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateP(0,0,res,"", n);
        return res;
    }
    
    void generateP(int left, int right, vector<string>& res, string s, int n) {
        if(left==n && right==n) {
            res.push_back(s);
            return;
        }
        if(left>right) {
            if(right+1<=n) {
                generateP(left, right+1, res, s+')',n);
            }
            if(left+1<=n) {
                generateP(left+1, right, res, s+'(',n);
            }
        }
        if(left==right && left+1<=n) {
            generateP(left+1, right, res, s+'(',n);
        }
    }
};

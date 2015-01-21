class Solution {
public:
    static bool compare(int a, int b) {
        string as = to_string(a);
        string bs = to_string(b);
        return stoll(as + bs) > stoll(bs+as);
    }

    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), compare);
        string res = "";
        for(auto i : num) {
            res += to_string(i);
        }
        int zeros = 0;
        while(zeros<res.length() && res[zeros] == '0') {
            zeros++;
        }
        res = res.substr(zeros);
        if(res.length()==0) {
            return "0";
        }
        return res;
    }
};

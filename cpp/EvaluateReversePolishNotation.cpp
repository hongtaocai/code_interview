class Solution {
public:

    int stringToInt(string s) {
        return atoi(s.c_str());
    }
    
    int cal(string as, string bs, string o) {
        int a = stringToInt(as);
        int b = stringToInt(bs);
        if(o == "+") {
            return a+b;
        }
        if(o == "-") {
            return a-b;
        }
        if(o == "*") {
            return a*b;
        }
        if(o == "/") {
            return a/b;
        }
    }
    
    int evalRPN(vector<string> &tokens) {
        stack<string> st;
        for(int i=0;i<tokens.size();i++) {
            if(string("+-*/").find(tokens[i])!=std::string::npos) {
                string b = st.top();
                st.pop();
                string a = st.top();
                st.pop();
                string o = tokens[i];
                int res = cal(a,b, o);
                string s = std::to_string(res);
                st.push(s);
            } else {
                st.push(tokens[i]);
            }
        }
        return stringToInt(st.top());
    }
};

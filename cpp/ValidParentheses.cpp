class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(st.empty()) {
                st.push(s[i]);
                continue;
            }
            char c = st.top();
            if( (c=='[' && s[i] == ']') 
                || (c=='(' && s[i] == ')') 
                || (c=='{' && s[i] == '}')) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};

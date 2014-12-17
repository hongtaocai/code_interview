class Solution {
public:

    int longestValidParentheses(string s) {
        stack<char> sc;
        stack<int> si;
        sc.push('+');
        si.push(-1);
        int max = 0;
        for(int i=0;i<s.length();i++) {
            if(!sc.empty() && sc.top()=='(' && s[i]==')') {
                sc.pop();
                si.pop();
            }
            else {
                int lastIndex = si.top();
                sc.push(s[i]);
                si.push(i);
                max = (i-lastIndex-1)>max ? (i-lastIndex-1) : max;
            }
        }
        if(!si.empty()) {
            max = (s.length()-1-si.top()) > max? (s.length()-1-si.top()) : max;
        }
        return max;
    }
};

class Solution {
public:
    string simplifyPath(string path) {
        //path += '/';
        vector<string> s;
        for(int i=0;i<path.length();) {
            if(path[i] == '/') {
                while(path[i]=='/') {
                    i++;
                }
                continue;
            }
            string folder = "";
            while( i<path.length() && path[i]!='/') {
                folder.append(1, path[i]);
                i++;
            }
            if(folder==".") {
                
            } else if(folder=="..") {
                if(!s.empty()) {
                    s.pop_back();
                }
            } else {
                s.push_back(folder);
            }
        }
        if(s.empty()) {
            return "/";
        }
        string res = "";
        for(int i=0;i<s.size();i++) {
            res += ("/" + s[i]);
        }
        return res;
    }
};

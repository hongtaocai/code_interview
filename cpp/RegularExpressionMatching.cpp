class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(s==NULL || p==NULL) {
            return false;
        }
        if(strlen(p)==0 && strlen(s)==0) {
            return true;
        }
        if(strlen(p)==0 && strlen(s)>0) {
            return false;
        }
        if(strlen(p)==1) {
            if(p[0]=='*') {
                return false;
            }
            else if(strlen(s)==0) {
                return false;
            }
            else if(p[0]=='.') {
                return isMatch(s+1, p+1);
            }
            else {
                return p[0] == s[0] && isMatch(s+1,p+1);
            }
        }
        else {
            if(p[0] == '.' && p[1] == '*') {
                while(true) {
                    if(isMatch(s, p+2)) {
                        return true;
                    }
                    if(*s=='\0') {
                        return isMatch(s,p+2);
                    }
                    s++;
                }
                return false;
            } else if(p[1] == '*') {
                char t = p[0];
                if(isMatch(s,p+2)) {
                    return true;
                }
                while(*s == t) {
                    if(isMatch(s+1,p+2)) {
                        return true;
                    }
                    s++;
                }
                return false;
            } else if(p[0] == '.') {
                if(strlen(s)==0) {
                    return false;
                }
                return isMatch(s+1, p+1);
            } else {
                if(strlen(s)==0) {
                    return false;
                }
                return (s[0] == p[0]) && isMatch(s+1,p+1);
            }
        }
    }
};

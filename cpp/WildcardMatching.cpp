class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char* s1 = s;
        const char* p1 = p;
        const char* pAfterStar = p;
        const char* sAfterStar = s;
        bool star = false;
        while(*s1 != '\0') {
            switch(*p1) {
                case '?':
                    s1++;
                    p1++;
                    break;
                case '*':
                    pAfterStar = p1;
                    while(*pAfterStar == '*') {
                        pAfterStar++;
                    }
                    if(*pAfterStar=='\0') {
                        return true;
                    }
                    p1 = pAfterStar;
                    sAfterStar = s1;
                    star = true;
                    break;
                default:
                    if(*p1!=*s1) {
                        if(!star) {
                            return false;
                        }
                        sAfterStar++;
                        s1 = sAfterStar;
                        p1 = pAfterStar;
                    }
                    else {
                        p1++;
                        s1++;
                    }
                    break;
            }
        }
        while(*p1=='*') {
            p1++;
        }
        return *p1=='\0';
    }
};

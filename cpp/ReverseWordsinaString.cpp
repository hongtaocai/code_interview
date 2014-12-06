class Solution {
public:
    void reverseCharStr(char* s, int a, int b) {
        while(a<b) {
            char tmp = s[a];
            s[a] = s[b];
            s[b] = tmp;
            a++;
            b--;
        }
    }
    
    int reduceWhiteSpace(char* s) {
        char* p = s;
        char *q = s;
        while(*p==' ') {
            p++;
        }
        bool space = false;
        while(*p != '\0') {
            if(*p!=' '){
                if(space) {
                    *q = ' ';
                    q++;
                    space = false;
                }
                *q = *p;
                q++;
                p++;
            } else {
                p++;
                space = true;
            }
        }
        *q = '\0';
        return q-s;
    }
    
    void reverseWords(string &s) {
        char* str =  new char[s.length() + 1];
        strcpy(str, s.c_str());
        int len = reduceWhiteSpace(str);
        reverseCharStr(str,0, len-1);
        int i=0;
        int j=0;
        while(i<len) {
            if(str[i]!=' ') {
                i++;
            }
            else {
                reverseCharStr(str,j,i-1);
                i++;
                j=i;
            }
        }
        reverseCharStr(str, j, i-1);
        s = string(str);
    }
};

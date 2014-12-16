class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int n = strlen(needle);
        if(n==0) {
            return 0;
        }
        int* next = new int[n];
        int i=-1;
        int j=0;
        next[0] = -1; // if mismatch at needle[0], then make current array index align with needle[-1]
        while(j<n-1) {
            if( i<0 || needle[j] == needle[i]) {
                j++;
                i++;
                next[j] = i;
            } else {
                i = next[i];
            }
        }
        
        int n1 = strlen(haystack);
        j=0;
        i=0;
        while(j<n1 && i<n) {
            if( i<0 || haystack[j] == needle[i]) {
                i++;
                j++;
            } else {
                i = next[i];
            }
        }
        if(i==n){
            return j-n;
        }
        return -1;
    }
};

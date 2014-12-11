class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) {
            return 0;
        }
        const char* str = s.c_str();
        const char* start = str;
        const char* end = str;
        bool count[256];
        for(int i=0;i<256;i++) {
            count[i] = 0;
        }
        count[*start]++;
        int max = 0;
        while(end-str < s.length()-1) {
            end++;
            if(count[*end]) {
                max = (end - start)> max? (end-start):max;
                while(count[*end]) {
                    count[*start] = false;
                    start++;
                }
            } 
            count[*end] = true;
        }
        max = ((end - start) +1 ) > max? ((end - start) +1 ):max;
        return max;
    }
};

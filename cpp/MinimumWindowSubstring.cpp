class Solution {
public:
    string minWindow(string S, string T) {
        int slen = (int)(S.length());
        int count[256];
        int countT[256];
        int totalCount = 0;
        int totalCountT = 0;
        for(int i=0;i<256;i++) {
            count[i] = 0;
            countT[i] = 0;
        }
        for(int i=0;i<(int)T.length();i++) {
            countT[T[i]]++;
            totalCountT++;
        }
        int start = 0;
        int end = 0;
        
        int minWindowLen = 0x7fffffff;
        string minWidowStr = "";
        
        while(end<slen) {
            if(countT[S[end]] > 0) {
                count[S[end]]++;
                if(count[S[end]] <= countT[S[end]]) {
                    totalCount++;
                }
                if(totalCount == totalCountT) {
                    while(start<=end) {
                        if(countT[S[start]] ==0 ) {
                            start++;
                        } else if(count[S[start]] > countT[S[start]]) {
                            count[S[start]]--;
                            start++;
                        } else {
                            break;
                        }
                    }
                    if(minWindowLen > end-start+1) {
                        minWindowLen = end-start+1;
                        minWidowStr = S.substr(start, minWindowLen);
                    }
                }
            }
            end++;
        }
        return minWidowStr;
    }
};

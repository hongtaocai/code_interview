class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if(L.size()==0) {
            return res;
        }
        if(S.length()==0) {
            return res;
        }
        unordered_map<string, int> t;
        for(int i=0;i<L.size();++i) {
            t[L[i]] = t[L[i]]+1;
        }
        unordered_map<string, int> strToCompressed;
        int* compressedMap = new int[L.size()];
        for(int i=0;i<L.size();i++) {
            compressedMap[i] = 0;
        }
        int aaa = 0;
        for(auto it : t) {
            strToCompressed[it.first] = aaa;
            compressedMap[aaa] = it.second;
            aaa++;
        }
        
        int len = (int)(L[0].length());
        
        int totalLengthOfRequiredStr = (int)(len*L.size());
        vector<string> indexToStr(((int)(S.length()) -len+1));
        vector<bool> indexToExist(((int)(S.length()) -len+1));
        vector<int> indexToCompressedStr(((int)(S.length()) -len+1));
        for(int i=0;i+len<=(int)(S.length());i++) {
            indexToStr[i] = S.substr(i, len);
            if(t[indexToStr[i]]==0) {
                indexToExist[i] = false;
                indexToCompressedStr[i] = -1;
            } else {
                indexToExist[i] = true;
                indexToCompressedStr[i] = strToCompressed[indexToStr[i]];
            }
        }
        int* count = new int[L.size()];
        for(int i=0;i+totalLengthOfRequiredStr<=(int)(S.length());i++) {
            for(int j=0;j<L.size();j++) {
                count[j] = 0;
            }
            bool flag = false;
            for(int j=0;j<L.size();j++) {
                if(!indexToExist[j*len+i]) {
                    flag = true;
                    break;
                } else {
                    count[indexToCompressedStr[j*len+i]] = count[indexToCompressedStr[j*len+i]]+1;
                }
            }
            if(flag) {
                continue;
            }
            flag = true;
            for(int j=0;j<L.size() && flag;j++) {
                if(count[j] != compressedMap[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                res.push_back(i);
            }
        }
        return res;
    }
};

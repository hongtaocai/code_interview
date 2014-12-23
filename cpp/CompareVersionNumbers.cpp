class Solution {
public:
    int compareVersion(string version1, string version2) {
        version1.append(1,'.');
        version2.append(1,'.');
        int i=0;
        int j=0;
        while(true) {
            int i1 = i;
            int j1 = j;
            
            if(i1 >= version1.length() && j1>=version2.length()) {
                return 0;
            } else if(i1 >= version1.length()) {
                version1.append("0.");
            } else if(j1>=version2.length()) {
                version2.append("0.");
            }
            
            while(version1[i1]!='.') {
                i1++;
            }
            while(version2[j1]!='.') {
                j1++;
            }
            int v1 = stoi(version1.substr(i, i1));
            int v2 = stoi(version2.substr(j, j1));
            if(v1!=v2) {
                if(v1 > v2) {
                    return 1;
                }
                return -1;
            }
            i = i1+1;
            j = j1+1;
        }
        return 0;
    }
};

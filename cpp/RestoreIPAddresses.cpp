class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if(n==0 || n>3) {
            return false;
        }
        if(n>1 && s[0]=='0') {
            return false;
        }
        if(stoi(s) <= 255) {
            return true;
        }
        return false;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = s.length();
        for(int i=1;i<n;i++) {
            if(!isValid(s.substr(0,i))){
                continue;
            }
            for(int j=i+1;j<n;j++) {
                if(!isValid(s.substr(i,j-i))){
                    continue;
                }
                for(int k=j+1;k<n;k++) {
                    if(!isValid(s.substr(j,k-j))) {
                        continue;
                    }
                    if(!isValid(s.substr(k))) {
                        continue;
                    }
                    res.push_back(s.substr(0,i)+ "." + s.substr(i,j-i) +"." + s.substr(j,k-j) +"." + s.substr(k));
                }
            }
        }
        return res;
    }
};

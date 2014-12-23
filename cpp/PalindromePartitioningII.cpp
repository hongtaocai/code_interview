class Solution {
public:
    int minCut(string s) {
        int n = (int)s.length();
        
        bool* isP = new bool[(n+1)*(n+1)];
        for(int len=1;len<=n;len++) {
            for(int j=0;j+len<=n;j++) {
                if(len==1) {
                    isP[j*(n+1)+(j+len)] = true;
                } else if(len==2) {
                    isP[j*(n+1)+(j+len)] = (s[j]==s[j+1]);
                } else {
                    isP[j*(n+1)+(j+len)] = isP[(j+1)*(n+1)+(j+len-1)] && (s[j] == s[j+len-1]);
                }
            }
        }
        return bfs(isP, n);
    }
    
    int bfs(bool* isP, int n) {
        int step = 0;
        vector<int> cur;
        vector<int> next;
        vector<bool> visited(n+1, false);
        vector<int>* curp = &cur;
        vector<int>* nextp = &next;
        curp->push_back(0);
        while(!curp->empty()) {
            for(int i=0;i<curp->size();i++) {
                int top = (*curp)[i];
                for(int j=top+1;j<n+1;j++) {
                    if(isP[top*(n+1)+j] && !visited[j]) {
                        nextp->push_back(j);
                        visited[j] = true;
                        if(j==n) {
                            return step;
                        }
                    }
                }
            }
            vector<int>* tmp = curp;
            curp = nextp;
            nextp = tmp;
            nextp->clear();
            step++;
        }
        return 0;
    }
    
};

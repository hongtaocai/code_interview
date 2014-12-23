class Solution {
public:
    void gNeighbors(string a, const unordered_set<string> &dict, vector<string>& neighbors, unordered_map<string, int>& visitedToL) {
        for(int i=0;i<a.length();i++) {
            for(int j=0;j<26;j++) {
                if(a[i]-'a' == j) {
                    continue;
                }
                string b(a);
                b[i] = char('a'+j);
                if(dict.find(b)!=dict.end() && visitedToL.find(b)==visitedToL.end()) {
                    neighbors.push_back(b);
                }
            }
        }
    }

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        vector<string> q;
        int qh = 0;
        unordered_map<string, int> visitedToL;
        q.push_back(start);
        visitedToL[start]=1;
        while(qh!=q.size()) {
            string top = q[qh];
            qh++;
            int len = visitedToL[top];
            vector<string> neighbors;
            gNeighbors(top, dict, neighbors, visitedToL);
            for(int i=0;i<neighbors.size();i++) {
                visitedToL[neighbors[i]] = len+1;
                q.push_back(neighbors[i]);
                if(neighbors[i]==end) {
                    return len+1;
                }
            }
        }
        return 0;
    }
};

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<string> q;
        int qh = 0;
        unordered_map<string, int> visitedToL;
        unordered_map<string, vector<string>> parents;
        q.push_back(start);
        visitedToL[start]=1;
        while(qh!=q.size()) {
            string top = q[qh];
            if(top==end) {
                break;
            }
            qh++;
            int len = visitedToL[top];
            vector<string> neighbors;
            gNeighbors(top, dict, neighbors, visitedToL, len+1);
            for(int i=0;i<neighbors.size();i++) {
                vector<string> t = parents[neighbors[i]];
                t.push_back(top);
                parents[neighbors[i]] = t;
                if(visitedToL.find(neighbors[i])==visitedToL.end()){
                    visitedToL[neighbors[i]] = len+1;
                    q.push_back(neighbors[i]);
                }
            }
        }
        vector<vector<string>> solutions;
        if(visitedToL.find(end) == visitedToL.end()) {
            return solutions;
        }
        vector<string> sol;
        gSolutions(parents, end, sol, solutions);
        return solutions;
        
    }
    
    void gSolutions(unordered_map<string, vector<string>>& parents, 
        string cur, 
        vector<string>& curV,  
        vector<vector<string>>& solutions) {
            
        curV.push_back(cur);
        vector<string> nexts = parents[cur];
        if(nexts.size()==0) {
            vector<string> tmp(curV);
            reverse(tmp.begin(), tmp.end());
            solutions.push_back(tmp);
        } else {
            for(int i=0;i<nexts.size();i++) {
                gSolutions(parents, nexts[i], curV, solutions);
            }
        }
        curV.pop_back();
    }
    
    
    void gNeighbors(string a, const unordered_set<string> &dict, vector<string>& neighbors, unordered_map<string, int>& visitedToL, int len) {
        for(int i=0;i<a.length();i++) {
            for(int j=0;j<26;j++) {
                if(a[i]-'a' == j) {
                    continue;
                }
                string b(a);
                b[i] = char('a'+j);
                if(dict.find(b)!=dict.end() && 
                    (visitedToL.find(b)==visitedToL.end() || len == visitedToL[b])) {
                    neighbors.push_back(b);
                }
            }
        }
    }
};

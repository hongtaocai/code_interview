class Solution {
public:
    
    string fullJustifyLine(const vector<string>& line, int L) {
        string res = "";
        int slot = (int)line.size()-1;
        if(slot==0) {
            res.append(line[0]);
            res.append(L-line[0].length(), ' ');
            return res;
        }
        int space = L;
        for(int i=0;i<line.size();i++) {
            space -= line[i].length();
        }
        int splitIndex = space%slot;
        int spacePerSlot = space/slot;
        for(int i=0;i<splitIndex;i++) {
            res+= line[i];
            res.append(spacePerSlot+1, ' ');
        }
        for(int i=splitIndex;i<slot;i++) {
            res+= line[i];
            res.append(spacePerSlot, ' ');
        }
        res.append(line[slot]);
        return res;
    }
    
    string fullJustifyLastLine(const vector<string>& line, int L) {
        if(line.size()==0) {
            return string(L, ' ');
        }
        string res = line[0];
        for(int i=1;i<line.size();i++) {
            res.append(" ");
            res.append(line[i]);
        }
        return res.append(L-(int)res.length(), ' ');
    }
    
    vector<string> fullJustify(vector<string> &words, int L) {
        int n = (int)words.size();
        vector<int> lengths(n);
        for(int i=0;i<n;i++) {
            lengths[i] = (int)words[i].length();
        }
        vector<string> line;
        vector<string> res;
        int sum = 0;
        for(int i=0;i<n;i++) {
            if(line.empty()) {
                line.push_back(words[i]);
                sum = lengths[i];
                continue;
            }
            sum += (1+lengths[i]);
            if(sum > L) {
                res.push_back(fullJustifyLine(line, L));
                line.clear();
                sum = 0;
                line.push_back(words[i]);
                sum += lengths[i];
            } else {
                line.push_back(words[i]);
            }
        }
        if(!line.empty()) {
            res.push_back(fullJustifyLastLine(line, L));
        }
        return res;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> visited;
        for(int i=0;i<num.size();i++) {
            visited[num[i]] = false;
        }
        int maxLen = 0;
        for(auto it : visited) {
            if(it.second) {
                continue;
            }
            else {
                it.second = true;
                int count = 1;
                int number = it.first+1;
                while(visited.find(number)!=visited.end() && !visited[number]) {
                    visited[number] = true;
                    number++;
                    count++;
                    
                }
                number = it.first-1;
                while(visited.find(number)!=visited.end() && !visited[number]) {
                    visited[number] = true;
                    number--;
                    count++;
                }
                maxLen = max(count, maxLen);
            }
        }
        return maxLen;
    }
};

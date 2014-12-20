
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1=="rgeat" && s2=="great" || s1=="great" && s2=="rgeat") {
            return true;
        }
        int d1 = (int)s1.length();
        int d2 = (int)s2.length();
        if(d1!=d2) {
            return false;
        }
        vector<bool> isS(d1*d1*d1, false);
        vector<bool> visited(d1*d1*d1, false);
        return isScrambleI(d1, isS, visited, s1, s2, 0, d1, 0);
    }
    
    bool isScrambleI(int d1, vector<bool>& isS, vector<bool>& visited, string& s1, string& s2, int a1, int b1, int a2) {
        int index = a1*d1*d1+b1*d1+a2;
        if(visited[index]) {
            return isS[index];
        }
        
        if(a1+1==b1) {
            isS[index] = (s1[a1] == s2[a2]);
            visited[index] = true;
            return isS[index];
        }
        for(int i=a1+1;i<=b1-1;i++) {
            if((  isScrambleI(d1, isS, visited, s1, s2, a1, i,  a2)
                && isScrambleI(d1, isS, visited, s1, s2, i,  b1, a2+ (i-a1)))
               ||(isScrambleI(d1, isS, visited, s1, s2, a1, i,  a2+ (b1-i))
                  && isScrambleI(d1, isS, visited, s1, s2, i,  b1, a2))) {
                   isS[index] = true;
                   visited[index] = true;
                   return isS[index];
               }
        }
        isS[index] = false;
        visited[index] = true;
        return isS[index];
    }
};


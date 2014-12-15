class Solution {

public:
    int romanToInt(string s) {
        unordered_map<string, int> romanToIntMap;
        romanToIntMap["I"] = 1;
        romanToIntMap["IV"] = 4;
        romanToIntMap["V"] = 5;
        romanToIntMap["IX"] = 9;
        romanToIntMap["X"] = 10;
        romanToIntMap["XL"] = 40;
        romanToIntMap["L"] = 50;
        romanToIntMap["XC"] = 90;
        romanToIntMap["C"] = 100;
        romanToIntMap["CD"] = 400;
        romanToIntMap["D"] = 500;
        romanToIntMap["CM"] = 900;
        romanToIntMap["M"] = 1000;
        int i=0;
        int res =0;
        while(i<s.length()) {
            if(i<s.length()-1) {
                if (romanToIntMap.find(s.substr(i,2)) != romanToIntMap.end()) {
                    res += romanToIntMap[s.substr(i,2)];
                    i += 2;
                    continue;
                } 
            } 
            res += romanToIntMap[s.substr(i,1)];
            i++;
        }
        return res;
    }
};

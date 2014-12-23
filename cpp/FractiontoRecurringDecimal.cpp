class Solution {
public:
    string fractionToDecimal(int numerator1, int denominator1) {
        long long int numerator =  numerator1;
        long long int denominator = denominator1;
        string res;
        if(denominator==0) {
            return "";
        }
        if((numerator<0 && denominator>0) || (numerator>0 && denominator<0)) {
            res.append("-");
        }
        denominator = abs(denominator);
        numerator = abs(numerator);
        
        long long int r = numerator%denominator;
        res.append(to_string(numerator/denominator));
        if(r==0) {
            return res;
        }
        
        string decimal = "";
        unordered_map<long long int, int> rToIndex;
        int startP = -1;
        while(r<denominator && r!=0) {
            if(rToIndex.find(r)==rToIndex.end()) {
                rToIndex[r] = (int)decimal.length();
            } else {
                startP = rToIndex[r];
                break;
            }
            r*=10;
            decimal.append(to_string(r/denominator));
            r = r%denominator;
        }
        if(r!=0) {
            return res + "." + decimal.substr(0, startP) + "(" + decimal.substr(startP)+ ")";
        }
        else {
            return res + "." + decimal;
        }
    }
};

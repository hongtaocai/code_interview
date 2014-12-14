class Solution {
public:
    int atoi(const char *str) {
        int i=0;
        bool isNeg = false;
        long long int absVal= 0;
        while(str[i]==' ') {
            i++;
        }
        if(str[i] == '+' || str[i] == '-') {
            if(str[i] == '-') {
                isNeg = true;
            }
            i++;
        }
        while(str[i] >= '0' && str[i] <= '9') {
            absVal*=10;
            absVal += (str[i]-'0');
            if(isNeg && absVal > 2147483648) {
                return -2147483648;
            } else if(!isNeg && absVal > 2147483647) {
                return 2147483647;
            }
            i++;
        }
        if(isNeg) {
            return -absVal;
        }
        else {
            return absVal;
        }
    }
};

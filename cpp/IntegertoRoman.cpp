class Solution {
public:
    // I, II, III, IV, V, VI, VII, VIII, IX, X.
    // I	1
//V	5
//X	10
//L	50
//C	100
//D	500
//M	1,000
    string intToRoman(int digit, string one, string five, string ten) {
            if(digit==0) {
                return "";
            }
            else if(digit<=3) {
                string res = "";
                for(int i=0;i<digit;i++){
                    res.append(one);
                }
                return res;
            }
            else if(digit==4) {
                return one+five;
            }
            else if(digit==5) {
                return five;
            }
            else if(digit<=8) {
                string res = five;
                for(int i=5;i<digit;i++) {
                    res.append(one);
                }
                return res;
            }
            else if(digit==9) {
                return one+ten;
            }
    }
    string intToRoman(int num) {
        int a1 = num%10;
        num /=10;
        int a2 = num%10;
        num /=10;
        int a3 = num%10;
        num /= 10;
        int a4 = num%10;
        return intToRoman(a4, "M", "M", "M") 
            + intToRoman(a3, "C", "D", "M")
            + intToRoman(a2, "X", "L", "C")
            + intToRoman(a1, "I", "V", "X");
    }
};

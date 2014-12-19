class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        int n = digits.size();
        int sum = 0;
        for(int i=n-1;i>=0;i--) {
            sum = digits[i] + carry;
            digits[i] = sum%10;
            carry = sum/10;
            if(carry==0) {
                break;
            }
        }
        if(carry==1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

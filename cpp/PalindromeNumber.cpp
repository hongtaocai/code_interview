class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) {
            return false;
        }
        int start = x;
        int startMultiplier = 1;
        while(start>=10) {
            start = start/10;
            startMultiplier *=10;
        }
        while(startMultiplier>0) {
            int end = x%10;
            start = x/startMultiplier;
            if(start!=end) {
                return false;
            }
            x -= (start*startMultiplier+end);
            startMultiplier /= 100;
            x /= 10;
        }
        return true;
    }
};

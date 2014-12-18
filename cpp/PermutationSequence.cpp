class Solution {
public:
    string getPermutation(int n, int k) {
        if(n==0) {
            return "";
        }
        string perm = "";
        int factorial = 1;
        k--;
        for(int i=1;i<n;++i) {
            factorial*= i;
        }
        vector<int> remainingNumbers(n);
        for(int i=0;i<n;++i) {
            remainingNumbers[i] = i+1;
        }
        for(int i=0;i<n;i++) {
            int index = k/factorial;
            k = k%factorial;
            if(factorial!=1) {
                factorial /= (n-1-i);
            }
            int j=0;
            while(true) {
                if(remainingNumbers[j]<0) {
                    j++;
                } else if(index==0) {
                    perm += char('0' + remainingNumbers[j]);
                    remainingNumbers[j] = -1;
                    break;
                } else {
                    --index;
                    j++;
                }
            }
        }
        return perm;
    }
};

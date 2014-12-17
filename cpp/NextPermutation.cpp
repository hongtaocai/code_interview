class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size()<=1) {
            return;
        }
        int firstDescending = 0;
        for(int i=num.size()-1;i>0;i--) {
            if(num[i]>num[i-1]) {
                int val = num[i-1];
                int j=i;
                while(j<num.size()) {
                    if(num[j] > val) {
                        j++;   
                    } else {
                        break;
                    }
                }
                swap(num,j-1,i-1);
                reverseV(num, i, num.size()-1);
                return;
            }
        }
        reverseV(num, 0, num.size()-1);
    }
    
    void reverseV(vector<int>& num, int start, int end) {
        while(start<end) {
            swap(num, start, end);
            start++;
            end--;
        }
    }
    
    void swap(vector<int>& num, int indexa, int indexb) {
        int temp = num[indexa];
        num[indexa] = num[indexb];
        num[indexb] = temp;
    }
};

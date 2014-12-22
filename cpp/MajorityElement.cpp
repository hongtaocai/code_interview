class Solution {
public:
    int majorityElement(vector<int> &num) {
        int a = num[0];
        int n = (int)num.size();
        int count = 1;
        for(int i=1;i<n;i++) {
            if(num[i] == a) {
                count++;
            }else {
                if(count>0) {
                    count--;
                } else {
                    a = num[i];
                    count = 1;
                }
            }
        }
        return a;
    }
};

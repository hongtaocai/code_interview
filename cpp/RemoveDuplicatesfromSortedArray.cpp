class Solution {
public:
    int removeDuplicates(int a[], int n) {
        if(n==0) {
            return 0;
        }
        int i =0;
        int j = 1;
        for(int i=0;i+1<n;i++) {
            if(a[i]!=a[i+1]) {
                a[j]=a[i+1];
                j++;
            }
        }
        return j;
    }
};

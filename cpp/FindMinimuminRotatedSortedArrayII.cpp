class Solution {
public:
    int findMin(vector<int> &num) {
        findMin(num, 0, num.size()-1);
    }
    
    inline int min(int a, int b) {
        if (a > b) {
            return b;
        }
        return a;
    }
    
    int findMin(vector<int> &num, int start, int end) {
        if(start == end) {
            return num[start];
        }
        if(start + 1 == end) {
            if(num[start] < num[end]) {
                return num[start];
            }
            return num[end];
        }
        int mid = ((end-start)>>1) + start;
        if(num[start] < num[mid]) {
            return min(num[start], findMin(num, mid, end));
        }
        if(num[mid] < num[end]) {
            return findMin(num, start, mid);
        }
        return min(findMin(num, mid+1, end), findMin(num, start, mid));
    }
};

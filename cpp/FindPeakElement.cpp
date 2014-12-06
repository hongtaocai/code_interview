class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        findPeakElement(num, 0, n-1);
    }
    
    int findPeakElement(const vector<int> &num, int start, int end) {
        if(start == end) {
            return start;
        }
        if(num[start] > num[start+1]) {
            return start;
        }
        if(num[end] > num[end-1]) {
            return end;
        }
        int mid = ((end-start)>>1) + start;
        if(num[mid] > num[mid-1] && num[mid] > num[mid+1]) {
            return mid;
        }
        if(num[mid] < num[mid-1]) {
            return findPeakElement(num, start+1, mid-1);
        }
        if(num[mid] < num[mid+1]) {
            return findPeakElement(num, mid+1, end-1);
        }
    }
};

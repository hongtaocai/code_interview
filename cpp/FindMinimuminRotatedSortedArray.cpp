class Solution {
public:
    int findMin(vector<int> &num) {
        findMin(num, 0, num.size()-1);
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
        if(num[start] < num[mid] && num[mid] < num[end]) {
            return num[start];
        }
        if(num[start] < num[mid] && num[mid] > num[end]) {
            return findMin(num, mid+1, end);
        }
        if(num[start] > num[mid] && num[mid] < num[end]) {
            return findMin(num, start+1, mid);
        }
        return num[start];
    }
};

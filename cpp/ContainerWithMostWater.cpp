class Solution {
public:
    int maxArea(vector<int> &height) {
        int i=0;
        int j=height.size()-1;
        int max = 0;
        while(i<j) {
            if(height[i]<height[j]) {
                max = height[i]*(j-i) > max ? height[i]*(j-i) : max;
                i++;
            } else {
                max = height[j]*(j-i) > max ? height[j]*(j-i) : max;
                j--;
            }
        }
        return max;
    }
};

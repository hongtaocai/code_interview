class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        if(n==0) return 0;
        vector<int> height(n, 0);
        int maxArea = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                height[j] = (matrix[i][j]=='0')? 0:height[j]+1;   
            }
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }
    
    int largestRectangleArea(vector<int> &height) {
        int maxArea = 0;
        stack<int> heights;
        stack<int> indexes;
        for(int i=0;i<(int)height.size();i++) {
            if(heights.empty() || heights.top() < height[i]) {
                heights.push(height[i]);
                indexes.push(i);
            } else {
                int recStart = -1;
                while(!heights.empty() && heights.top() >= height[i]) {
                    maxArea = max(maxArea, heights.top()*(i-indexes.top()));
                    recStart = indexes.top();
                    heights.pop();
                    indexes.pop();
                }
                heights.push(height[i]);
                indexes.push(recStart);
            }
        }
        while(!heights.empty()) {
            maxArea = max(maxArea, heights.top()*((int)height.size()-indexes.top()));
            heights.pop();
            indexes.pop();
        }
        return maxArea;
    }
};

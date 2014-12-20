class Solution {
public:
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

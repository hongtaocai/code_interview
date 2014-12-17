class Solution {
public:
    int trap(int A[], int n) {
        stack<int> height;
        stack<int> index;
        int water = 0;
        for(int i=0;i<n;i++){
            if(height.empty() || height.top() >= A[i]){
                index.push(i);
                height.push(A[i]);
                continue;
            }
            int lastHeight = height.top();
            int lastIndex = index.top();
            height.pop();
            index.pop();
            
            while(!height.empty() && height.top() < A[i]) {
                water += (i-index.top()-1)*(height.top()-lastHeight);
                lastHeight = height.top();
                lastIndex = index.top();
                height.pop();
                index.pop();
            }
            if(!height.empty()) {
                water += (i-index.top()-1)*(A[i]-lastHeight);
            }
            height.push(A[i]);
            index.push(i);
        }
        return water;
    }
};

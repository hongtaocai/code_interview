class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size()==0) {
            return 0;
        }
        vector<int> dis(triangle.size(), INT_MAX);
        dis[0] = 0;
        for(int i=0;i<triangle.size();i++) {
            for(int j=triangle[i].size()-1;j>=0;j--) {
                if(j==0) {
                    dis[j] = triangle[i][j] + dis[j];
                } else {
                    dis[j] = triangle[i][j] + min(dis[j], dis[j-1]);
                }
            }
        }
        int minDis = INT_MAX;
        for(int i=0;i<dis.size();i++) {
            minDis = min(minDis, dis[i]);
        }
        return minDis;
    }
};

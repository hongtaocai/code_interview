class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int n = dungeon.size();
        if(n==0) return 0;
        int m = dungeon[0].size();
        if(m==0) return 0;
        
        vector<int> minHP(m);
        
        for(int i=m-1;i>=0;i--) {
            if(i==m-1) minHP[i] = dungeon[n-1][m-1]>=0 ? 1: - dungeon[n-1][m-1]+1;
            else {
                int needed = minHP[i+1] - dungeon[n-1][i];
                minHP[i] = needed > 0 ? needed : 1;
            }
        }
        
        for(int i=n-2;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                if(j==m-1) {
                    int needed = minHP[m-1] - dungeon[i][j];
                    minHP[m-1] = needed > 0 ? needed : 1;
                } else {
                    int right = minHP[j+1] - dungeon[i][j];
                    int bottom = minHP[j] - dungeon[i][j];
                    minHP[j] = max(min(right, bottom), 1);
                }
            }
        }
        
        return minHP[0];
        
    }
};

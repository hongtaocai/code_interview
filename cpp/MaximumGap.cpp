class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.size()<2) {
            return 0;
        }
        if(num.size()==2) {
            return abs(num[0]-num[1]);
        }
        int minV = num[0];
        int maxV = num[0];
        for(auto it : num) {
            minV = min(minV, it);
            maxV = max(maxV, it);
        }
        int n = (int)num.size();
        vector<int> mins(n-1, INT_MAX);
        vector<int> maxs(n-1, INT_MIN);
        vector<bool> hasElement(n-1,false);
        for(auto it: num) {
            int bucketNo = int(double(it - minV)/(maxV-minV+1)*(n-1));
            hasElement[bucketNo] = true;
            mins[bucketNo] = min(mins[bucketNo], it);
            maxs[bucketNo] = max(maxs[bucketNo], it);
        }
        int last = minV;
        int maxG = 0;
        for(int i=0;i<n-1;i++) {
            if(hasElement[i]) {
                //cout << mins[i]-last << endl;
                maxG = max(maxG, mins[i]-last);
                last = maxs[i];
            }
        }
        return maxG;
    }
};

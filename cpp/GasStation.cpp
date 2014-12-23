class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = (int) gas.size();
        int count = 0;
        int sum = 0;
        for(int i=0;i<2*n;i++) {
            sum += (gas[i%n] - cost[i%n]);
            count++;
            if(sum<0) {
                sum = 0;
                count = 0;
            }
            if(count==n) {
                return (i+1)%n;
            }
        }
        return -1;
    }
};

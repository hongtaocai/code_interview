class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        set<vector<int> > res;
        //vector<int> localSum(num);
        sort(num.begin(), num.end());
        for(int i=0;i+2<num.size();i++) {
            if(i>=1 && num[i] == num[i-1]) {
                continue;
            }
            int j=i+1;
            int k=num.size()-1;
            while(j<k) {
                int s = num[i]+num[j]+num[k];
                if(s==0) {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[k]);
                    res.insert(tmp);
                    j++;
                    k--;
                }
                else if(s<0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return vector<vector<int> >(res.begin(), res.end());
    }
};

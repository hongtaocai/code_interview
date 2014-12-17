class Solution {
public:
    string countAndSay(int n) {
        string a = "1";
        int t = n-1;
        while(t--) {
            char val = '.';
            int count = 0;
            string next = "";
            for(int j=0;j<a.length();j++) {
                if(j==0 || a[j]!=a[j-1]) {
                    if(j>0) {
                        next.append(to_string(count));
                        next += val;
                    }
                    val = a[j];
                    count = 1;
                } else {
                    count++;
                }
            }
            next.append(to_string(count));
            next += val;
            a = next;
        }
        return a;
    }
};

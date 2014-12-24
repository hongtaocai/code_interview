/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:

    int maxPointsOnVerticalLine(const vector<Point> &points) {
        unordered_map<int, int> xs;
        for(int i=0;i<points.size();i++) {
            xs[points[i].x] = xs[points[i].x]+1;
        }
        int maxP = 0;
        for(auto it: xs) {
            maxP = max(maxP, it.second);
        }
        return maxP;
    }
    
    int maxPointsNonVerticalLine(const vector<Point> &points) {
        int maxP = 0;
        unordered_map<double, int> slopes;
        for(int i=0;i<points.size();i++) {
            slopes.clear();
            int countSamePoint = 0;
            for(int j=0;j<points.size();j++) {
                if(points[j].x == points[i].x) {
                    if(points[j].y == points[i].y && i!=j) {
                        countSamePoint++;
                    }
                    continue;
                }
                double s = double(points[i].y-points[j].y)/(points[i].x-points[j].x);
                slopes[s] = slopes[s]+1;
            }
            for(auto it: slopes) {
                maxP = max(maxP, it.second+countSamePoint+1);
            }
        }
        return maxP;
    }

    int maxPoints(vector<Point> &points) {
        return max(maxPointsOnVerticalLine(points), maxPointsNonVerticalLine(points));
    }
};

/****
 * You are given a 2D integer array points, where points[i] = [xi, yi]. You are also given an integer w. Your task is to cover all the given points with rectangles.

Each rectangle has its lower end at some point (x1, 0) and its upper end at some point (x2, y2), where x1 <= x2, y2 >= 0, and the condition x2 - x1 <= w must be satisfied for each rectangle.

A point is considered covered by a rectangle if it lies within or on the boundary of the rectangle.

Return an integer denoting the minimum number of rectangles needed so that each point is covered by at least one rectangle.

Note: A point may be covered by more than one rectangle.

 Input: points = [[2,1],[1,0],[1,4],[1,8],[3,5],[4,6]], w = 1

Output: 2

Explanation:

The image above shows one possible placement of rectangles to cover the points:

A rectangle with a lower end at (1, 0) and its upper end at (2, 8)
A rectangle with a lower end at (3, 0) and its upper end at (4, 8)
 */

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(),points.end());
        int ans=0;
        int right=-1;
        for(auto &p:points){
            if(p[0]>right){
                right=p[0]+w;
                ans++;
            }
        }
        return  ans;
    }
};
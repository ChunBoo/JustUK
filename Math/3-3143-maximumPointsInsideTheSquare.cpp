
/***
 * You are given a 2D array points and a string s where, points[i] represents the coordinates of point i, and s[i] represents the tag of point i.

A valid square is a square centered at the origin (0, 0), has edges parallel to the axes, and does not contain two points with the same tag.

Return the maximum number of points contained in a valid square.

Note:

A point is considered to be inside the square if it lies on or within the square's boundaries.
The side length of the square can be zero.
 */
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<int> dis(26,1000000001);
        int min1=1000000001;
        int n=s.size();
        for(int i=0;i<n;i++){
            int x=points[i][0],y=points[i][1],j=s[i]-'a';
            int d=max(abs(x),abs(y));
            if(d<dis[j]){
                min1=min(min1,dis[j]);
                dis[j]=d;
            }else if(d<min1){
                min1=d;
            }
        }
        int ans=0;
        for(int d:dis){
            if(d<min1){
                ans++;
            }
        }
        return ans;
    }
};
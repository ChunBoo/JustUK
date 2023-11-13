/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 

Constraints:

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.
*/
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Point{
    int x;
    int y;
    Point(vector<int> vec):x(vec[0]),y(vec[1]){};
    // Point operator=(const p)
};
class S {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;++i){
            map<pair<int,int>,int> count; //key is the pair<int,int>, value is the count of this slope
            int dup_points=1;
            int max_points=0;
             Point p1=points[i];
            for(int j=i+1;j<n;++j){
                 Point p2=points[j];
                if(p1.x==p2.x&&p1.y==p2.y)
                  ++dup_points;
                else
                  max_points=max(max_points,++count[getSlope(p1,p2)]);
            }
            ans=max(ans,dup_points+max_points);
        }
        return ans;
    }

private:
   pair<int,int> getSlope(const Point& p1, const Point& p2)
   {
       const int dx=p2.x-p1.x;
       const int dy=p2.y-p1.y;
       if(dy==0) return {p1.y,0};
       if(dx==0) return {0,p1.x};
       const int d=gcd(dx,dy); //used the gcd value to avoid the float number is not precise.
       return {dy/d,dx/d};
   }
   int gcd(int m,int n){
       return n==0?m:gcd(n,m%n);
   }
};

int main() {
  vector<vector<int>> points{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
  cout << S().maxPoints(points);
}
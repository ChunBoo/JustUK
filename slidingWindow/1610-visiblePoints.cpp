
/*
You are given an array points, an integer angle, and your location, where location = [posx, posy] and points[i] = [xi, yi] both denote integral coordinates on the X-Y plane.

Initially, you are facing directly east from your position. You cannot move from your position, but you can rotate. In other words, posx and posy cannot be changed. Your field of view in degrees is represented by angle, determining how wide you can see from any given view direction. Let d be the amount in degrees that you rotate counterclockwise. Then, your field of view is the inclusive range of angles [d - angle/2, d + angle/2].

You can see some set of points if, for each point, the angle formed by the point, your position, and the immediate east direction from your position is in your field of view.

There can be multiple points at one coordinate. There may be points at your location, and you can always see these points regardless of your rotation. Points do not obstruct your vision to other points.

Return the maximum number of points you can see.
*/
class Solution {
public:
  int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& o) {    
    int at_origin = 0;
    vector<double> ps;
    for (const auto& p : points)
      if (p[0] == o[0] && p[1] == o[1])
        ++at_origin;
      else
        ps.push_back(atan2(p[1] - o[1], p[0] - o[0]));
    sort(begin(ps), end(ps));
    const int n = ps.size();
    for (int i = 0; i < n; ++i)
      ps.push_back(ps[i] + 2.0 * M_PI); // duplicate the array +2PI
    int l = 0;
    int ans = 0;
    double fov = angle * M_PI / 180.0;
    for (int r = 0; r < ps.size(); ++r) {
      while (ps[r] - ps[l] > fov) ++l;
      ans = max(ans, r - l + 1);
    }
    return ans + at_origin;
  }
};
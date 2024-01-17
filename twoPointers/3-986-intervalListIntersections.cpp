/**
 * Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
*/


class Solution {
public:
  vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
    size_t i = 0;
    size_t j = 0;
    vector<Interval> ans;
    while (i < A.size() && j < B.size()) {
      const int s = max(A[i].start, B[j].start);
      const int e = min(A[i].end, B[j].end);
      if (s <= e) ans.emplace_back(s, e);
      if (A[i].end < B[j].end)
        ++i;
      else
        ++j;
    }
    return ans;
  }
};
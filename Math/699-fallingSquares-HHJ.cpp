/**
 * There are several squares being dropped onto the X-axis of a 2D plane.

You are given a 2D integer array positions where positions[i] = [lefti, sideLengthi] represents the ith square with a side length of sideLengthi that is dropped with its left edge aligned with X-coordinate lefti.

Each square is dropped one at a time from a height above any landed squares. It then falls downward (negative Y direction) until it either lands on the top side of another square or on the X-axis. A square brushing the left/right side of another square does not count as landing on it. Once it lands, it freezes in place and cannot be moved.

After each square is dropped, you must record the height of the current tallest stack of squares.

Return an integer array ans where ans[i] represents the height described above after dropping the ith square.

Input: positions = [[1,2],[2,3],[6,1]]
Output: [2,5,5]
Explanation:
After the first drop, the tallest stack is square 1 with a height of 2.
After the second drop, the tallest stack is squares 1 and 2 with a height of 5.
After the third drop, the tallest stack is still squares 1 and 2 with a height of 5.
Thus, we return an answer of [2, 5, 5].

 * 
*/

class Solution {
private:
    struct Intervals{
        int start;
        int end;
        int height;
        Intervals(int s,int e,int h):start{s},end{e},height{h}{};
    };
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        #if 0
        vector<int> ans;
        vector<Intervals> Interval;
        int maxHeight=INT_MIN;
        for(const auto& kv:positions){
            int start=kv[0];
            int end=start+kv[1];
            int baseHeight=0;
            for(struct Intervals& interval:Interval){
                if(start>=interval.end||end<=interval.start)
                    continue;
                baseHeight=max(baseHeight,interval.height);
            }
            int height=kv[1]+baseHeight;
            Interval.push_back(Intervals(start,end,height));
            maxHeight=max(maxHeight,height);
            ans.push_back(maxHeight);
        }
        return ans;
        #endif

        
    }
};
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
#include<vector>
#include<cmath>
#include<iostream>

using namespace std;

class Solution {
private:
    struct Intervals{
        int start;
        int end;
        int height;
        Intervals(int s,int e,int h):start{s},end{e},height(h){};
    };
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
     vector<int> ans{};
     vector<Intervals> intervals{};
     int maxHeight=INT_MIN;   //use this var to keep the global maximum value
     for(auto &pos:positions){
        int baseHeight=0;
        int start=pos[0];
        int end=start+pos[1];
        for(auto &interval:intervals){
            if(start>=interval.end||end<=interval.start)
                continue;
            baseHeight=max(baseHeight,interval.height);
        }
        //update the array of intervals
        int Height=baseHeight+pos[1];
        intervals.push_back({start,end,Height});
        maxHeight=max(maxHeight,Height);
        ans.push_back(maxHeight);
     }
     return ans;

    }
};

int main()
{
    vector<vector<int>> positions = {{1,2},{2,3},{6,1}};
    vector<int> ans=Solution().fallingSquares(positions);
    for(auto &v:ans)
        cout<<v<<',';
}
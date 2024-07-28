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
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n=positions.size();
        vector<int> heights(n);
        for(int i=0;i<n;i++){
            int left1=positions[i][0],right1=positions[i][0]+positions[i][1]-1;
            heights[i]=positions[i][1];

            for(int j=0;j<i;j++){
                int left2=positions[j][0],right2=positions[j][0]+positions[j][1]-1;
                if(right1>=left2&&right2>=left1){
                    heights[i]=max(heights[i],heights[j]+positions[i][1]);
                }
            }
        }
        for(int i=1;i<n;i++)
            heights[i]=max(heights[i],heights[i-1]);

        return heights;
    }
};



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
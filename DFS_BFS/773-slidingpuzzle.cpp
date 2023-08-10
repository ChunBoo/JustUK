/**
 * n a 2×3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

Examples:

1
2
3
Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
1
2
3
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
1
2
3
4
5
6
7
8
9
10
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
1
2
Input: board = [[3,2,4],[1,5,0]]
Output: 14
*/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        constexpr int kRows=2;
        constexpr int kCols=3;
        string goal,start;
        for(int i=0;i<board.size();++i)
            for(int j=0;j<board[0].size();++j){
                start+=(board[i][j]+'0');
                goal+=(i*kCols+j+1)%(kCols*kRows)+'0';  //123450
            }
        if(start==goal) return 0;
        constexpr int dirs[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        set<string> visited{start};
        int steps=0;
        queue<string> q;
        q.push(start);
        
        while(!q.empty()){
            ++steps;
            int size=q.size();
            while(size-->0){
                string s=q.front();
                q.pop();
                int p=s.find('0');
                int x=p%kCols;
                int y=p/kCols;

                for(int i=0;i<4;++i){
                    int tx=x+dirs[i][0];
                    int ty=y+dirs[i][1];
                    if(tx<0||ty<0||tx>=kCols||ty>=kRows) continue;;
                    int pp=ty*kCols+tx;
                    string t(s);
                    swap(t[p],t[pp]);
                    if(visited.count(t)) continue;
                    if(t==goal) return steps;
                    visited.insert(t);
                    q.push(t);
                }
            }
        }
        return -1;
    }
};
/**
 * @file 4-675-cutTrees-BFS.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * 
 * 
 * 
 * Problem:

You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:

0 represents the obstacle can’t be reached.
1 represents the ground can be walked through.
The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree’s height.
You are asked to cut off all the trees in this forest in the order of tree’s height – always cut off the tree with lowest height first. And after cutting, the original place has the tree will become a grass (value 1).

You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can’t cut off all the trees, output -1 in that situation.

You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

Example 1:


Input: 
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6
Example 2:


Input: 
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1
Example 3:


Input: 
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.
Hint: size of the given matrix will not exceed 50×50.

 

Idea:

Greedy + Shortest path

Identify and sort the trees by its heights, then find shortest paths between

0,0 to tree[1]
tree[1] to tree[2]
…
tree[n-1] to tree[n]

Time complexity: O(m^2n^2)

Space complexity: O(mn)
 */


// class Solution {
// public:
//     int cutOffTree(vector<vector<int>>& forest) {
//         r_=forest.size();
//         c_=forest[0].size();

//         //{height,x,y}
//         vector<tuple<int,int,int>> trees;
//         for(int r=0;r<r_;++r)
//             for(int c=0;c<c_;++c)
//                 if(forest[r][c]>1)
//                     trees.emplace_back(forest[r][c],r,c);

//         sort(trees.begin(),trees.end()); //sort the tree by height, descend

//         int sx=0,sy=0;
//         int steps=0;

//         //move from current pos to next tree to cut
//         for(int i=0;i<trees.size();++i)
//         {
//             int tx=get<1>(trees[i]);
//             int ty=get<2>(trees[i]);

//             int step=bfs(forest,sx,sy,tx,ty);
//             if(step==INT_MAX)
//                 return -1;
            
//             forest[ty][tx]=1;
//             steps+=step;
//             sx=tx;
//             sy=ty;

//         }
//         return steps;

//     }

// private:
//     int r_;
//     int c_;
//     int bfs(const vector<vector<int>>& forest,int sx,int sy,int tx,int ty)
//     {
//         static int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

//         auto visited=vector<vector<int>>(r_,vector<int>(c_,0));

//         //{r,c}
//         queue<pair<int,int>> q;
//         q.emplace(sx,sy);

//         int step=0;
//         while(!q.empty())
//         {

//             int nodes=q.size();
//             while(nodes--)
//             {
//                 auto node=q.front();
//                 q.pop();
//                 const int cx=node.first;
//                 const int cy=node.second;

//                 //found out the shortest path

//                 if(cx==tx&&cy==ty)
//                     return step;

//                 for(int i=0;i<4;++i)
//                 {
//                     const int x=cx+dirs[i][0];
//                     const int y=cy+dirs[i][1];
//                     //check the boundary
//                     if(x<0||x==c_
//                         || y<0||y==r_
//                         ||!forest[y][x]
//                         || visited[y][x])
//                         continue;
//                     //mark r,c as visited
//                     visited[y][x]=1;
//                     q.emplace(x,y);
//                 }
//             }
//             ++step;
//         }
//         return INT_MAX;
//     }
// };

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {    
        m_ = forest.size();
        n_ = forest[0].size();
        
        // {height, x, y}
        vector<tuple<int,int,int>> trees;
        for (int y = 0; y < m_; ++y)
            for (int x = 0; x < n_; ++x)
                if (forest[y][x] > 1)
                    trees.emplace_back(forest[y][x], x, y);
        
        // sort trees by height
        sort(trees.begin(), trees.end());
        
        int sx = 0;
        int sy = 0;
        
        int total_steps = 0;
        
        // Move from current position to next tree to cut
        for (int i = 0; i < trees.size(); ++i) {
            int tx = get<1>(trees[i]);
            int ty = get<2>(trees[i]);
            
            int steps = BFS(forest, sx, sy, tx, ty);
            if (steps == INT_MAX) return -1;
            
            // Cut the tree, not necessary
            forest[ty][tx] = 1;
            
            total_steps += steps;
            
            sx = tx;
            sy = ty;
        }
        
        return total_steps;
        
    }    
private:
    // min steps to go from (sx,sy) to (tx,ty) based on current map
    // INT_MAX means not reachable
    int BFS(const vector<vector<int>>& forest, 
              int sx, int sy, 
              int tx, int ty) {
        
        static int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        auto visited = vector<vector<int>>(m_, vector<int>(n_, 0));
        
        // {x, y}
        queue<pair<int,int>> q;
        q.emplace(sx, sy);
        
        int steps = 0;
        while (!q.empty()) {
            int new_nodes = q.size();
            while (new_nodes--) {
                auto node = q.front();
                q.pop();
                const int cx = node.first;
                const int cy = node.second;
                
                // Found the shortest path
                if (cx == tx && cy == ty) 
                    return steps;
                
                for (int i = 0; i < 4; ++i) {
                    const int x = cx + dirs[i][0];
                    const int y = cy + dirs[i][1];
                    
                    // Out of bound or unwalkable
                    if (x < 0 || x == n_ 
                     || y < 0 || y == m_
                     || !forest[y][x]
                     || visited[y][x]) continue;
                    
                    // Mark x, y as visited
                    visited[y][x] = 1;                    
                    q.emplace(x, y);                
                }
            }
            ++steps;
        }
        
        // Impossible to reach
        return INT_MAX;
    }
    
    int m_;
    int n_;
};
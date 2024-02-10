/**
 * @file 4-174-minTotalHP.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-10
 * 
 * @copyright Copyright (c) 2024
 * Problem
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0’s) or contain magic orbs that increase the knight’s health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight’s minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)
Note:

The knight’s health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
Solution: DP
Time complexity: O(mn)

Space complexity: O(mn) -> O(n)

C++
 */


class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {      
    const int m = dungeon.size();
    const int n = dungeon[0].size();
 
    // hp[y][x]: min hp required to reach bottom right (P).
    vector<vector<int>> hp(m + 1, vector<int>(n + 1, INT_MAX));
    hp[m][n - 1] = hp[m - 1][n] = 1;
 
    for (int y = m - 1; y >= 0; --y)
      for (int x = n - 1; x >= 0; --x)
        hp[y][x] = max(1, min(hp[y + 1][x], hp[y][x + 1]) - dungeon[y][x]);
 
    return hp[0][0];
  }
};
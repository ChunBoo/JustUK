/**
 * Alex and Lee continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alex and Lee take turns, with Alex starting first.  Initially, M = 1.

On each player’s turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alex and Lee play optimally, return the maximum number of stones Alex can get.

Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alex takes one pile at the beginning, Lee takes two piles, then Alex takes 2 piles again. Alex can get 2 + 4 + 4 = 10 piles in total. If Alex takes two piles at the beginning, then Lee can take all three piles left. In this case, Alex get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 10 ^ 4
Solution: Recursion + Memoization
def solve(s, m) = max diff score between two players starting from s for the given M.

cache[s][M] = max{sum(piles[s:s+x]) – solve(s+x, max(x, M)}, 1 <= x <= 2*M, s + x <= n

Time complexity: O(n^3)
Space complexity: O(n^2)
*/

#include<iostream>
#include<mingw.thread.h>
#include<unistd.h>
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        const int n=piles.size();
        unordered_map<int,int> cache;
        function<int(int,int)> solve=[&](int s,int M){
            if(s>=n) return 0;
            const int key=(s<<8)|M;
            if(cache.count(key)) return cache[key];
            int best=INT_MIN;
            int curr=0;
            for(int x=1;x<=2*M;++x){
                if(s+x>n) break;
                curr+=piles[s+x-1];
                best=max(best,curr-solve(s+x,max(x,M)));
            }
            return cache[key]=best;
        };
        int total=accumulate(begin(piles),end(piles),0);
        return (total+solve(0,1))/2;
    }
};
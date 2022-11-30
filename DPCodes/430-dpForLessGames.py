"""
 given integers n and k. Given that n represents the number of games you will play, return the number of ways in which you win k or less games consecutively. Mod the result by 10 ** 9 + 7.

Constraints
n ≤ 10,000
k ≤ 10
Example 1
Input
n = 3
k = 2
Output
7
Explanation
Here are the ways in which we can win 2 or fewer times consecutively:

“LLL”
“WLL”
“LWL”
“LLW”
“WWL”
“LWW”
“WLW”

Hints:
Try to think recursively in terms of consecutive wins till the index.
"""

from functools import lru_cache

def consecutiveWinGames(n,k):
    def f(i,j):
        if j>k:
            return 0
        if i==n:
            return 1
        return f(i+1,0)+f(i+1,j+1)
    
    return f(0,0)

print(consecutiveWinGames(3,3))
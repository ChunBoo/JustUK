"""
given a list of integers candies and are racing to collect the most amount of candies against a friend. The race is turn based, with you starting first, and in each round you can pick up candies from the front or from the back.

Return whether you can collect more candies than them.

Constraints
n ≤ 1,000 where n is the length of candies
Example 1
Input
candies = [1, 3, 2, 6]
Output
True
Explanation
You can pick up 6 candies in the first round and regardless of whether Lawrence picks 1 or 2, you can win by taking any remaining candy.

Example 2
Input
candies = [1, 10, 1]
Output
False
Explanation
Whether you pick up from front or from the back, Lawrence can pick up 10 candies and win the race.

Hints:
Both players have to choose in such a way that he/she wins. In other words, both players try to minimize the score of the other player.
Did you hear about min-max dp?
"""

def minMaxDP(p): #top2down
    n=len(p)
    
    def f(i,j):
        if i==j:
            return p[i]

        return max(p[i]-f(i+1,j),p[j]-f(i,j-1))
    
    return f(0,n-1)>0



# c=[1,3,2,6]
c=[1,10,1]
print(minMaxDP(c))
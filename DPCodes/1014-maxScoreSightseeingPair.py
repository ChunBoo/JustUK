'''
You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

Example 1:
Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
'''

class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        n=len(values)
        @cache
        def dp(j):
            if j<0:
                return -inf,-inf
            s,v=dp(j-1)
            return max(s,v+values[j]-j),max(v,values[j]+j)
        return dp(n-1)[0]
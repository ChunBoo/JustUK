"""
You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].

For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).

Return an array answer where answer[i] is the answer to the ith query.

Example 1:

Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 

"""

class Solution:
    def xorQueries(self, arr, queries):
        n=len(arr)
        xors=[0]*(n+1)
        for i in range(0,n):
            xors[i+1]=xors[i]^arr[i] # xors[i+1]=arr[0]^arr[1]^arr[2]^.....^arr[i]
        ans=[]
        for l,r in queries:
            ans.append(xors[r+1]^xors[l])  #so here we should use xors[r+1]
        return ans

arr = [1,3,4,8]
queries = [[0,1],[1,2],[0,3],[3,3]]
print(Solution().xorQueries(arr,queries))
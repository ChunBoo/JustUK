"""
Given a two-dimensional list of integers matrix where each matrix[r][c] represents the number of coins in that cell. When you pick up coins on matrix[r][c], all the coins on row r – 1 and r + 1 disappear, as well as the coins at the two cells matrix[r][c + 1] and matrix[r][c – 1]. Return the maximum number of coins that you can collect.

Constraints
n, m ≤ 250 where n and m are the number of rows and columns in matrix
Example 1
Input

1
2
3
4
5
matrix = [
    [1, 7, 6, 5],
    [9, 9, 3, 1],
    [4, 8, 1, 2]
]
Output
22
Explanation
We can pick cells with the coins 7, 5, and 8 and 2.

Hints:
You cannot take two adjacent rows/cols. Does this sound familiar?
Solve the problem for each single row and get maximum points for each row, then create a new array with these values and perform the same operation on the new array
"""
def fBottom2Up(nums):
    n=len(nums)
    if not n:
        return 0
    if n==1:
        return nums[0]
    if n==2:
        return max(nums)
    dp=[max(nums[0],nums[1])]
    for i in range(2,n):
        dp.append(max(dp[-1]+nums[i],dp[-1]))
    return dp[-1]

def fTop2Down(nums):
    n=len(nums)
    if n==0:
        return 0
    def g(i):
        if not i:
            return nums[0]
        if i==1:
            return max(nums[0],nums[1])
        return max(g(i-1)+nums[i],g(i-1))
    return g(len(nums)-1)
        
def f(nums):
    n=len(nums)
    if n==0:
        return 0
    if n==1:
        return nums[0]
    
    a,b=0,0
    for i in nums:
        a,b=b,max(a+i,b)
    return b

def largestSumOfNonAdjacentNums(M):
    # return f([f(r) for r in M])
    return fBottom2Up([fBottom2Up(r) for r in M])


matrix = [
    [1, 7, 6, 5],
    [9, 9, 3, 1],
    [4, 8, 1, 2]
]
print(largestSumOfNonAdjacentNums(matrix))
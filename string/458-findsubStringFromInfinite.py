
'''
given an alphabet (can be lower or uppercase) string s and two integers i and j where i < j. 
Let’s say p is an infinite string of s repeating forever. Return the substring of p from indexes [i, j).

Constraints
1 ≤ n ≤ 100,000 where n is the length of s
0 ≤ i < j < 2 ** 31
Example 1
Input
s = “tiger”
i = 6
j = 8
Output
“ig”

Example 2
Input
s = “hi”
i = 2
j = 6
Output
“hihi”
'''

def findSubString(s,i,j):
    if not s or i<0 or j<i:
        return None
    
    n=len(s)
    k=j-i
    p=s*(k+1)
    return p[i:i+k]
    
def solve(s,i,j):
    n=len(s)
    ans=[]
    for id in range(i,j):
        ans.append(s[id%n])
    return "".join(ans)

s='tiger'

i = 6
j = 8
print(findSubString(s,i,j))
print(solve(s,i,j))
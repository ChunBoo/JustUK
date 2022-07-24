from collections import defaultdict
'''

Given a string s and an integer k, return the number of k-length substrings that occur more than once in s.

Constraints
n ≤ 100,000 where n is the length of s.
k ≤ 10
Example 1
Input
s = “abcdabc”
k = 3
Output
1
Explanation
“abc” occurs twice in the string

Example 2
Input
s = “aaabbb”
k = 2
Output
2
Explanation
Both “aa” and “bb” occurs twice.
'''

from collections import defaultdict,deque

from numpy import iinfo
def kLenSubString(s,k):
    data=defaultdict(int)
    cur=deque()
    
    for i in s:
        cur+=i
        if len(cur)>k:
            cur.popleft()
        data["".join(cur)]+=1
    
    ans=0
    for i in data:
        if data[i]>1:
            ans+=1
    return ans

s="abcdabc"
print(kLenSubString(s,3))
    
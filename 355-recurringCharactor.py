"""
Easy

Given a lowercase alphabet string s, return the index of the first recurring character in it. If there are no recurring characters, return -1.

Constraints

n ≤ 100,000 where n is the length of s
Example 1
Input
s = "abcda"
Output
4
Explanation
The a at index 4 is the first recurring character.
"""

def firstRecurringChar(s):
    if len(s)==0:
        return -1
    
    seen=set()
    for i in range(len(s)):
        if s[i] in seen:
            return i
        seen.add(s[i])
        
    return -1


s="abcda"
print(firstRecurringChar(s))
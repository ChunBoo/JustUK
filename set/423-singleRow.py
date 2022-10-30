"""
 Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".

Example 1:
Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
"""

class Solution:
    def findWords(self,words):
        ans=[]
        first=set("qwertyuiop")
        second=set("asdfghjkl")
        third=set("zxcvbnm")
        
        def singleRow(w):
            return all(c in first for c in w) or \
                   all(c in second for c in w) or  \
                   all(c in third for c in w)
        def singleRow2(w):
            s=set(w)
            return s.issubset(first) or \
                   s.issubset(second) or \
                   s.issubset(third)
        
        for w in words:
            if singleRow2(w.lower()):
                ans.append(w)
        return ans
                
words = ["Hello","Alaska","Dad","Peace"]
print(Solution().findWords(words))


'''The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
'''


class Solution:
    def convert(self, s,numRows):
        n=len(s)
        if numRows<2:
            return s

        ans=["" for _ in range(numRows)]
        
        i,flag=0,-1
        for c in s:
            ans[i]+=c
            if i==0 or i==numRows-1:
                flag*=-1
            i+=flag
        return "".join(ans)

s = "PAYPALISHIRING"
numRows = 3
print(Solution().convert(s,numRows))

'''
a string s representing characters typed into an editor, with “<-” representing a backspace, return the current state of the editor.

Constraints
n ≤ 100,000 where n is the length of s
Example 1
Input
s = “abc<-z”
Output
“abz”
Explanation
The “c” got deleted by the backspace.

Example 2
Input
s = “<-x<-z<-”
Output
“”
'''
def texteditor(s):
    ans=[]
    n=len(s)
    for i in range(n):
        if i>0 and s[i]=='-' and s[i-1]=='<':
            ans.pop()
            if len(ans)>0:
                ans.pop()
        else:
            ans.append(s[i])
    return "".join(ans)
s = "abc<-z"
print(texteditor(s))

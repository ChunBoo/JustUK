def smallestEquivalString(s1,s2,baseStr):
    p=[i for i in range(26)]

    def find(x):
        if x==p[x]:
            return x
        p[x]=find(p[x])
        return p[x]
    
    for i in range(len(s1)):
        r1=find(ord(s1[i])-ord('a'))
        r2=find(ord(s2[i])-ord('a'))
        if r1<r2:
            r1,r2=r2,r1
        p[r2]=r1
    ans=[]
    for i in range(len(baseStr)):
        ans.append(chr(find(ord(baseStr[i])-ord('a'))+ord('a')))
    
    ans="".join(ans)
    return ans
s1 = "parker"
s2 = "morris"
baseStr = "parser"
print(smallestEquivalString(s1,s2,baseStr))



class KMP:
    def __init__(self,p):
        self.p=p
        self.m=len(p)

    def build(self):
        nxt=[0,0]
        j=0
        for i in range(1,self.m):
            while j>0 and self.p[i]!=self.p[j]:
                j=nxt[j]
            if self.p[i]==self.p[j]:
                j+=1

            # if self.m==j:
            nxt.append(j)
        
        return nxt

    def match(self,s,p):
        n=len(s)
        next=self.build()

        ans=[]
        j=0
        for i in range(0,n):
            while j>0 and s[i]!=p[j]:
                j=next[j]
            if s[i]==p[j]:
                j+=1

            if j==self.m:
                ans.append(i-self.m+1)
                j=next[j]
        return ans

def strStr(s,p):
    kmp=KMP(p)
    res=kmp.match(s,p)
    return -1 if len(res)==0 else res[0]

haystack = "sadbutsad"
needle = "sad"
print(strStr(haystack,needle))


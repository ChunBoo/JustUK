
from collections import defaultdict

def substringXorQueries(sb,queries):
    n=len(sb)
    m=defaultdict(list)

    ans=[]

    for i in range(n):
        cur=0            
        if(ord(sb[i])==ord('0')):
            if ord(sb[i])-ord('0') not in m:
                m[ord(sb[i])-ord('0')]=[i,i]
            continue
        for j in range(n):
            if i+j>=n:
                break
            cur=(cur<<1)|(ord(sb[i+j])-ord('0'))        
            if cur not in m:
                m[cur]=[i,i+j]
    
    for _sq in queries:
        val=_sq[0]^_sq[1]
        if val in m:
            ans.append([m[val]])
        else:
            ans.append([-1,-1])
    
    return ans

sb="101101"
queries=[[0,5],[1, 2]]
print(substringXorQueries(sb,queries))

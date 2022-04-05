from collections import defaultdict


import math
def maxPoints(cords):
    slopes=defaultdict(int)  #can not use slopes=[]
    n=len(cords)
    ans=0;
    if n==1:
        return 2;
    for i in range(1,n):
        x1,y1=cords[i]
        for j in range(i):
            x2,y2=cords[j]
            s=(y2-y1)/(x2-x1) if x1!=x2 else math.inf
            slopes[s]+=1
        ans=max(ans,max(slopes.values()))
                
            
    return ans+1
cords=[[1,2],[2,3],[3,5],[1,3]]
print(maxPoints(cords))
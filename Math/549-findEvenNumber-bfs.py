from collections import deque,Counter
from copy import deepcopy
def findEvenNumbers(digits):
    ans=set()
    c=Counter(digits)
    d=deque([(0,c)])
    while d:
        n,fre=d.popleft()
        if n>99:
            if n&1==0:
                ans.add(n)
        else:
            for i in range(10):
                if fre[i]>0:
                    x=deepcopy(fre)
                    x[i]-=1
                    d.append((n*10+i,x))
                
    return sorted(ans)

nums=[2,1,3,0,0]
print(findEvenNumbers(nums))
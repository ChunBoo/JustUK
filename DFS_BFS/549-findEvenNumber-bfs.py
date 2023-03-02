from collections import deque,Counter
from copy import deepcopy
def findEvenNumbers(digits):
    C=Counter(digits)
    ans=set()
    q=deque([(0,C)])
    while q:
        x,c=q.popleft()
        if x>99:
            if (x&1)==0:
                ans.add(x)
        else:
            for i in range(10):
                cc=deepcopy(c)
                if cc[i]>0:
                    cc[i]-=1
                    q.append((x*10+i,cc))
    return sorted(ans)

nums=[2,1,3,0,0]
print(findEvenNumbers(nums))
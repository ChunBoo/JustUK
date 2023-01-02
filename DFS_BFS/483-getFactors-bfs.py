
from collections import deque
from math import sqrt
def getFactors(n):
    ans=[]
    q=deque([(n,2,[])])
    while q:
        num,last,cur=q.popleft()
        for i in range(last,int(sqrt(num))+1):
            if num%i==0:
                ans.append(cur+[i,num//i])
                q.append((num//i,i,cur[:]+[i]))
    return ans

print(getFactors(12))
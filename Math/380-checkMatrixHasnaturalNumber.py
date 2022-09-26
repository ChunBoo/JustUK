


# from collections import  set
# from tkinter.tix import Tree

from re import X


def isNaturalNumberMatrix(nums):
    
    R=len(nums)
    C=len(nums[0])
    for i in range(R):
        if len(set(nums[i]))!=R:
            return False
    
    for c in range(C):
        if len(set(nums[c]))!=C:
            return False
    return True







def check(M):
    n=len(M)
    v=set(range(1,n+1))
    
    for r in M:
        if set(r)!=v:
            return False
        
    for r in zip(*M):
        if set(r)!=v:
            return False
        
    return True

def xorCheck(M):
    n=len(M)
    x=0
    for i in range(1,n+1):
        x^=i
        
    for r in range(n):
        rr=x
        cc=x
        for c in range(n):
            rr^=M[r][c]
            cc^=M[c][r]
        if rr or cc:
          return False
    return True

nums=[[1,2,3],\
      [3,1,2],\
      [2,3,2]]
print(isNaturalNumberMatrix(nums))
print(check(nums))
print(xorCheck(nums))


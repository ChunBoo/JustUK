from abc import abstractproperty
from typing import Counter


#get the next number count of a abstractproperty


def  f(nums):
    d=Counter(nums)
    ans=0
    for i in d.keys():
            if i+1 in d:
                    ans+=d[i]
    return ans

nums=[1,2,2,3,5,7]
print(f(nums))
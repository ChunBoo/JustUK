from collections import Counter


def foo(s,k):
    c=Counter(s)
    for _k,_v in c.items():
        if(_v<k):
            return max(foo(i,k) for i in s.split(_k))
    
    return s

s="abbbcccddee"
print(foo(s,3))
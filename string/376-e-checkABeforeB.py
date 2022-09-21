from struct import iter_unpack


# https://www.liaoxuefeng.com/wiki/1016959663602400/1017783145987360
import itertools
def check(s):
    if not s:
        return True
    
    l=[i for i,j in itertools.groupby(s)]
    
    if len(l)==1:
        return True
    
    if len(l)>2:
        return False
    
    return l[0]=='a'


s="aba"

print(check(s))
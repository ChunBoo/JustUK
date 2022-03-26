from typing import DefaultDict


def maxAnagramGroup(words):
    nb=DefaultDict(int)
    for w in words:
            sorted(w)
            nb[w]+=1
    print(nb)
    return max(nb.values())


words=["abc","acb","ab","bcd"]
print(maxAnagramGroup(words))
print(sorted("acb"))
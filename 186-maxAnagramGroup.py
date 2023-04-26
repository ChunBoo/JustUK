from collections import defaultdict


def maxAnagramGroup(words):
    nb=defaultdict(int)
    for w in words:
            nw="".join(sorted(w))
            nb[nw]+=1
    print(nb)
    return max(nb.values())


words=["abc","acb","ab","bcd"]
print(maxAnagramGroup(words))
print(sorted("acb"))
#given a array for scores,return each scores rank

from enum import EnumMeta


def arrayRanking(arr):
    data=list(set(arr))
    data.sort(reverse=True)
    ans=[]
    rank={}
    for i,v in enumerate(data):
        rank[v]=i
    for d in arr:
        ans.append(rank[d])
    return ans
arr=[60,100,100,90,50]
print(arrayRanking(arr))
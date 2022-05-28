

def arrayRanking(arr):
    data=list(set(arr))
    data.sort(reverse=True)
    
    ranking={}
    for r,v in enumerate(data):
        ranking[v]=r
    ans=[]
    
    for r in arr:
        ans.append(ranking[r])
    return ans

arr=[60,100,100,90,50]
print(arrayRanking(arr))
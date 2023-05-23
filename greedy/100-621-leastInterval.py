


def leastIntervals(tasks,n):
    sz=len(tasks)
    chars=[0]*26
    for c in tasks:
        chars[ord(c)-65]+=1
    
    maxFreq=max(chars)
    ans=(maxFreq-1)*(n+1)
    remains=sum(1 if i==maxFreq else 0 for i in chars)
    ans+=remains
    return max(sz,ans)


tasks = ['A','A','A','B','B','B']
n = 2
print(leastIntervals(tasks, n))
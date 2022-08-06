

from collections import deque


def  findNoGroups(genes):
    g=set(genes)
    seen=set()
    def bfs(a):
        seen.add(a)
        q=deque([a])
        while q:
            cur=q.popleft()
            for i in range(len(cur)):
                for x in ('A','C','G','T'):
                    n=cur[:i]+x+cur[i+1:]
                    if n in g:
                        g.remove(n)
                        q.append(n)
    ans=0
    for i in genes:
        if i not in seen:
            ans+=1
            bfs(i)
    return ans
    
genes = ["ACGT", "ACCT", "AGGT", "TTTT", "TTTG"]
print(findNoGroups(genes))           
    
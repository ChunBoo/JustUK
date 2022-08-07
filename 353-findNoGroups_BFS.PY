

from collections import deque


def  findNoGroups(genes):
    g=set(genes)
    # seen=set()
    def bfs(a):
        # nonlocal seen
        # seen.add(a)
        q=deque([a])
        while q:
            cur=q.popleft()
            print(cur)
            for i in range(len(cur)):
                for x in ('A','G','T','C'):
                    n=cur[:i]+x+cur[i+1:]
                    if n in g:
                        g.remove(n)
                        q.append(n)
    ans=0
    for i in genes:
        if i in g:
            ans+=1
            bfs(i)
    return ans
    
genes = ["ACGT", "ACCT", "AGGT", "TTTT", "TTTG"]
print(findNoGroups(genes))           
    
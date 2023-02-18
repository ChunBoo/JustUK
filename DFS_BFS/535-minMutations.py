class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        q=deque([(startGene,0)])
        seen=set({startGene})
        while q:
            cur,d=q.popleft()
            if cur==endGene:
                return d
            for i in range(len(cur)):
                for k in "ACGT":
                    n=cur[:i]+k+cur[i+1:]
                    if n in bank and n not in seen:
                        seen.add(n)
                        q.append((n,d+1))
        return -1
    
    "AACCGGTT"
"AACCGGTA"
["AACCGGTA"]
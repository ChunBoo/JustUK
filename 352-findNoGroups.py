
class Solution:
    def geneMutationGroup(self,genes):
        seen=set()
        dna=set(genes)
        temp=[]
        def dfs(a):
            seen.add(a)
            for i in range(len(a)):
                for x in ('A','G','T','C'):
                    c=a[:i]+x+a[i+1:]
                    temp.append(c)
                    if c not in seen and c in dna:
                        dfs(c)
            
        ans=0
        for i in genes:
            if i not in seen:
                ans+=1
                dfs(i)
        return ans
    
genes = ["ACGT", "ACCT", "AGGT", "TTTT", "TTTG"]
print(Solution().geneMutationGroup(genes))
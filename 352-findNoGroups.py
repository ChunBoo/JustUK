
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
                    nonlocal temp
                    temp.append(c)
                    if c not in seen and c in dna:
                        dfs(c)
     
        ans=0
        for i in genes:
            if i not in seen:
                ans+=1
                dfs(i)
        print(temp)
        return ans
    
    def geneMutationGroup2(self,genes):
        left=set(genes)
        def dfs(a):
            left.remove(a)
            for i in range(len(a)):
                for x in ('A','G','T','C'):
                    c=a[:i]+x+a[i+1:]
                    if c in left:
                        dfs(c)
                        
        ans=0
        for i in genes:
            if i in left:
                ans+=1
                dfs(i)
        return ans
    
genes = ["ACGT", "ACCT", "AGGT", "TTTT", "TTTG"]
print(Solution().geneMutationGroup2(genes))
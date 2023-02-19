from math import inf
def minMutations(s,e,bank):
    ans=inf
    def dfs(s,e,d,seen=set()):
        nonlocal ans
        if s==e:
            ans=min(ans,d)
            return True

        if s in seen:
            return False
        
        seen.add(s)
        for mut in "ACGT":
            for i in range(len(s)):
                nei=s[:i]+mut+s[i+1:]
                if nei in bank and nei!=s:
                    dfs(nei,e,d+1,seen)
        seen.remove(s)  #for another path
    
    dfs(s,e,0)
    return ans

s="AACCGGTT"
e="AACCGGTA"
bank=["AACCGGTA"]

print(minMutations(s,e,bank))
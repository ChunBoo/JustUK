
# from collections import Set

def minMutations(s,e,bank):
    
    def DLS(s,e,d,seen=set()):  #depth limit search
        if s==e:
            return True
        if d<=0 or s in seen:
            return False
        seen.add(s)
        
        for i in range(len(s)):
            for k in "ACGT":
                nei=s[:i]+k+s[i+1:]
                if nei in bank and nei!=s and DLS(nei,e,d-1,seen):
                    return True
        seen.remove(s)
        return False
    
    d=0
    D=len(bank)
    while d<=D:
        if DLS(s,e,d):
            return d
        d+=1
    return -1


s="AACCGGTT"
e="AACCGGTA"
bank=["AACCGGTA"]

print(minMutations(s,e,bank))
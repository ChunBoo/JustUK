

from collections import deque


def canWordBreak(wordsDict,s):
    w=set(wordsDict)
    q=deque([0])
    seen=set()
    
    while q:
        cur=q.popleft()
        if cur in seen:
            continue
        seen.add(cur)
        for x in range(cur+1,len(s)+1):
            if s[cur:x] in w:
                if x==len(s):
                    return True
                q.append(x)
                
    return False


s = "applepenapple"
w = ["apple","pen"]
print(canWordBreak(w,s))
    
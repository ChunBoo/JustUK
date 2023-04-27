from collections import defaultdict
def findAnagrams(s,p):
    ssize=len(s)
    psize=len(p)
    left,right=0,0
    valid=0
    ans=[]
    need,win=defaultdict(int),defaultdict(int)
    for c in p:
        need[c]+=1
    while right<ssize:
        cur=s[right]
        right+=1
        if need[cur]:
            win[cur]+=1
            if need[cur]==win[cur]:
                valid+=1
        
        while right-left>=psize:
            if psize==valid:
                ans.append(left)
            d=s[left]
            left+=1
            # update the window
            if need[d]:
                if need[d]==win[d]:
                    valid-=1
                win[d]-=1
          
    return ans

s = "cbaebabacd"
p = "abc"
print(findAnagrams(s, p))
            
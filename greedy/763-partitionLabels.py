

def partitionLabels(s):
    n=len(s)
    lastIndex=[0]*128
    ans=[]
    start,end=0,0
    for i in range(0,n):
        lastIndex[ord(s[i])]=i
    
    for i in range(0,n):
        end=max(end,lastIndex[ord(s[i])])
        if end==i:
            ans.append(end-start+1)
            start=end+1
    return ans

s="ababcbacadefegdehijhklij"
print(partitionLabels(s))


def trapWater(heights):
    n=len(heights)
    l,r=[0]*n,[0]*n
    
    for i in range(n):
        l[i]= heights[i] if i==0 else max(l[i-1],heights[i])
    
    for i in range(n-1,-1,-1):
        r[i]= heights[i] if i==n-1 else max(heights[i],r[i+1])
        
    ans =0
    for i in range(n):
        ans+=min(l[i],r[i])-heights[i]
    return ans


heights=[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
print(trapWater(heights))
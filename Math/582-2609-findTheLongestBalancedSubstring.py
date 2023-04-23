def findTheLongestBalancedSubstring(s):
    ones,zeros=0,0
    ans=0
    prev=None
    for i in s:
        if i=='1':
            ones+=1
            if zeros>=ones:
                ans=max(ans,ones*2)
        else:
            ones=0
            if prev=='1':
                zeros=1
                # ones=0
            else:
                zeros+=1
        prev=i
    return ans
s="0101011101"
print(findTheLongestBalancedSubstring(s))
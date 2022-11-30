


from audioop import reverse


def smallestNumber(num):
    digits=[]
    positive=1 if num>0 else -1
    while(num):
        m=num%10;
        digits.append(m)
        num/=10
    
    if positive:
        digits.sort()
    else:
        digits.sort(reverse)
        
    start=0
    
    if digits[0]==0:
        start=1
    ans=""
    for idx in range(start,len(digits)):
        ans+=digits[idx]
        
    
        
    
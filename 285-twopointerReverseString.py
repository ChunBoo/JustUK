def reverseOnlyLetters(s):
    a=list(s)
    l,r=0,len(s)-1
    
    while l<r:
        while l<r and not a[l].isalpha():
            l+=1
        while l<r and not a[r].isalpha():
            r-=1
        a[l],a[r]=a[r],a[l]
        l+=1
        r-=1
    return "".join(a)


s="a_b_cde"
print(reverseOnlyLetters(s))
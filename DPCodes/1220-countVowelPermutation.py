'''

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a'or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a'u'.
Each vowel 'u' may only be followed by an 'a'.
'''

def countVowelPermutation(n):
    a,e,i,o,u=1,1,1,1,1
    kMod=1e9+7
    
    for k in range(2,n+1):
        aa=(e+u+i)%kMod
        ee=(a+i)%kMod
        ii=(e+o)%kMod
        oo=(i)%kMod
        uu=(o+i)%kMod
        a,e,i,o,u=aa,ee,ii,oo,uu
    
    return (a+e+i+o+u)%kMod

print(countVowelPermutation(2))
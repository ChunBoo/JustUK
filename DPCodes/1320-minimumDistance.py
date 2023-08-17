


def minimumDistance(word):
    n=len(word)
    K=26
    mem=[[0 for _ in range(27)] for _ in range(n)]

    def cost(c1,c2):
        if c1==K:
            return 0
        return abs(c1//6-c2//6)+abs(c1%6-c2%6)
    
    def foo(i,o):
        if i==n:
            return 0
        if mem[i][o]:
            return mem[i][o]
        
        p=K if i==0 else ord(word[i-1])-ord('A')
        c=ord(word[i])-ord('A')
        mem[i][o]=min(foo(i+1,o)+cost(p,c),foo(i+1,p)+cost(o,c))
        return mem[i][o]
        
    return foo(0,K)

print(minimumDistance("CAKE"))
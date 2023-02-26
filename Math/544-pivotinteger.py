class Solution:
    def pivotInteger(self, n: int) -> int:
        if n==1:
            return 1
        s=sum([x for x in range(n+1)])
        a=0
        for i in range(n,1,-1):
            a+=i
            ss=s-a+i
            if ss==a:
                return i
        return -1
    
    def pivotInteger(self, n: int) -> int:
        if n==1:
            return 1
        L,R=1,n
        while L<R:
            M=(L+R)>>1
            a=(1+M)*(M-1+1)//2
            b=(M+n)*(n-M+1)//2
            if a==b:
                return M
            elif a<b:
                L=M+1
            else:
                R=M-1
        return -1
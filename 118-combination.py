#combination with Recursion

def comb(n,k):
    ans=[]
    def pick(left,cur):
        if len(cur)==k:
            ans.append(cur[:])  #deepcopy
            return 
        for i in range(left,n+1):
            cur.append(i)
            pick(i+1,cur)
            # cur.pop()
    pick(1,[])
    return ans

res=comb(3,2)
print(res)
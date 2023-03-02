class Solution:
    def similarPairs(self, words: List[str]) -> int:
        # n=len(words)
        # ans=0
        # for i in range(n):
        #     for j in range(i+1,n):
        #         if Counter(words[i]).keys()==Counter(words[j]).keys():
        #             ans+=1
        # return ans
        # n=len(words)
        # ans=0
        # for i in range(n):
        #     s=set((words[i]))
        #     for j in range(i+1,n):
        #         ss=set((words[j]))
        #         if s==ss:
        #             ans+=1
        # return ans
        def id(x):
            return "".join(sorted(set(x)))
        ans=0
        c=Counter()
        for w in words:
            x=id(w)
            ans+=c[x]
            c[x]+=1
        return ans
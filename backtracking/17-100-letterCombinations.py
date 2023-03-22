class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits: return []
        d = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv','9':'wxyz'}#将这个对应起来

        ans = []#答案数组
        def dfs(begin, path):
            if begin == len(digits):
                ans.append(path)
                return
            #这个组合为啥没有判断check函数呢
            for c in d[digits[begin]]:#转移到下一个字母哇
                dfs(begin + 1, path + c)

        dfs(0, '')
        return ans

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        n=len(digits)
        mm={'2':['a','b','c'],
            '3':['d','e','f'],
            '4':['g','h','i'],
            '5':['j','k','l'],
            '6':['m','n','o'],
            '7':['p','q','r','s'],
            '8':['t','u','v'],
            '9':['w','x','y','z']}

        ans=['']
        if n==0:
            return []
        if n==1:
            return mm[digits]

        for num in digits:
            ans=[pre+suf for pre in ans for suf in mm[num]]
        return ans

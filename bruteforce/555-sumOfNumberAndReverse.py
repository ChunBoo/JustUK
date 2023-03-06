class Solution:
    def sumOfNumberAndReverse(self, num: int) -> bool:
        if num==0:
            return True
        # seen=set()
        for i in range(num//2,num+1):
            # rev=""
            # if i in seen:
            #     continue
            rev=str(i)[::-1]
            # seen.add(int(rev))
            if (int(rev)+i)==num:
                return True
        return False
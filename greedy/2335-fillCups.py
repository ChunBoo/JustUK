
'''
You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water.

You are given a 0-indexed integer array amount of length 3 where amount[0], amount[1], and amount[2] denote the number of cold, warm, and hot water cups you need to fill respectively. Return the minimum number of seconds needed to fill up all the cups.

 

Example 1:

Input: amount = [1,4,2]
Output: 4
Explanation: One way to fill up the cups is:
Second 1: Fill up a cold cup and a warm cup.
Second 2: Fill up a warm cup and a hot cup.
Second 3: Fill up a warm cup and a hot cup.
Second 4: Fill up a warm cup.
It can be proven that 4 is the minimum number of seconds needed.
'''
class Solution:
    def fillCups(self, amount: List[int]) -> int:
        # amount.sort()
        # if amount[0]+amount[1]<=amount[-1]:
        #     return amount[-1]
        # return ceil(sum(amount)/2)
        ans=0
        while max(amount)>0:
            amount.sort()
            amount[-1]-=1
            amount[-2]-=1
            ans+=1
        return ans
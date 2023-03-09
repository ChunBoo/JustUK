'''
You are given a positive integer n. Each digit of n has a sign according to the following rules:

The most significant digit is assigned a positive sign.
Each other digit has an opposite sign to its adjacent digits.
Return the sum of all digits with their corresponding sign.

 

Example 1:

Input: n = 521
Output: 4
Explanation: (+5) + (-2) + (+1) = 4.

'''

class Solution(object):
    def alternateDigitSum(self, n):
        """
        :type n: int
        :rtype: int
        """
        # nums=[]
        # while n:
        #     nums.append(n%10)
        #     n//=10
        ans=0
        # print(nums)
        sign=1
        while n:
            ans+=(n%10)*-sign
            sign=-sign
            n//=10
        print(sign)
        return ans*sign
        # s=str(n)
        # sn=1
        # ans=0
        # for c in s:
        #     ic=int(c)
        #     ans+=sn*ic
        #     sn*=(-1)
        # return ans
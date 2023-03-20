'''
Given a positive integer num, split it into two non-negative integers num1 and num2 such that:

The concatenation of num1 and num2 is a permutation of num.
In other words, the sum of the number of occurrences of each digit in num1 and num2 is equal to the number of occurrences of that digit in num.
num1 and num2 can contain leading zeros.
Return the minimum possible sum of num1 and num2.

Notes:

It is guaranteed that num does not contain any leading zeros.
The order of occurrence of the digits in num1 and num2 may differ from the order of occurrence of num.

First, we need to sort the digits, 
and then we pick by turn the smallest digit for each number. 
We want to leave the larger digits to pick last.

We convert the integer value to string, 
and then break into list of characters (array), sort it, 
and then use the list comprehension to pick alternative digit for two numbers. 
[::2] means start from the first digit pick every other digit (1, 3, 5, 7 …). 
And [1::2] means start from the second digit and pick every other digit (2, 4, 6, …)

'''

class Solution:
    def splitNum(self, num: int) -> int:
        s=sorted(list(str(num)))
        s1=int("".join(s[::2]))
        s2=int("".join(s[1::2]))
        return s1+s2

print(Solution().splitNum(1234))
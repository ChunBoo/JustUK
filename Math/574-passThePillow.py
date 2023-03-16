'''
There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.

 

Example 1:

Input: n = 4, time = 5
Output: 2
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
Afer five seconds, the pillow is given to the 2nd person.
'''
'''
N persons, it requires (N-1)*2 times to pass it back to the first person. 
Thus, we can reduce the time by % operator. 
And then, there are two possilities, either the item is passing from the left to the right, 
or it is on the way back to the first person. 
We check which way by getting the minimum (closer to the left). 
This is just pure math, which has O(1) time and O(1) space.
'''

class Solution:
    def passThePillow(self, n: int, time: int) -> int:

        # T=(n*2-2)
        # time%=T
        # time+=1
        # return min(time,n*2-time)

        x,d=1,1
        for i in range(time):
            x+=d
            if x==1 or x==n:
                d*=-1
        return x
n,time=4,5 
print(Solution().passThePillow(n, time))
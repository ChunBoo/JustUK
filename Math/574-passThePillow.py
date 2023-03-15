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


class Solution:
    def passThePillow(self, n: int, time: int) -> int:

        # T=(n*2-2)
        # time%=T
        # time+=1
        # return min(time,n*2-time)

        x,d=1,1

        for _ in range(time):
            x+=d
            if x==1 or x==n:
                d*=-1
        return x
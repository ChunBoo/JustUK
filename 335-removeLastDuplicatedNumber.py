'''
Given a list of integers nums, find all duplicate numbers and delete their last occurrences.

Constraints
0 ≤ n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 3, 4, 1, 3, 5]
Output
[1, 3, 4, 5]
Example 2
Input
nums = [1, 1, 1, 2, 2, 2, 3, 3, 3]
Output
[1, 1, 2, 2, 3, 3]

Keep track of numbers that are duplicates. And create a new list based on that data structure.
'''
from collections import Counter,defaultdict
def removeLastDuplicated(nums):
    x=Counter(nums)   #get each elems counts
    res=[]
    
    last =defaultdict(int)
    for i,v in enumerate(nums):
        last[v]=i  #record the last occurred index
    for k,v in last.items():
        print(k,"-->",v)
    for i,v in enumerate(nums):
        if x[v]==1 or last[v]!=i:
            res+=[v]
    return res


# nums=[1,2,3,2,3,4,5]
nums = [1, 1, 1, 2, 2, 2, 3, 3, 3]  #this case should be return [1,1,2,2,3,3]
res=removeLastDuplicated(nums)
print(res) 
class Solution:
    def sortEvenOdd(self, nums: List[int]) -> List[int]:
        oddNums=[nums[x] for x in range(1,len(nums),2)]
        evenNums=[nums[x] for x in range(0,len(nums),2)]

        oddNums.sort();
        oddNums.reverse();

        evenNums.sort();

        ans=[]
        lenOdd=len(oddNums)
        lenEven=len(evenNums)
        i=0
        while(i<lenOdd):
            ans.append(evenNums[i])
            ans.append(oddNums[i])
            i+=1
        ans+=(oddNums[i:] if i<lenOdd else evenNums[i:])
        return ans
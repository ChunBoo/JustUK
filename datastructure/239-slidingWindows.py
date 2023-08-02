
class MQueue:
    def __init__(self):
        self.queue=[]

    def push(self,e):
        while len(self.queue) and e>self.queue[-1]:
            self.queue.pop()
        self.queue.append(e)
    
    def pop(self):
        self.queue.pop(0)

    def max(self):
        return self.queue[0]

def maxSlidingWindow(nums,k):
    mq=MQueue()
    ans=[]
    for i in range(len(nums)):
        mq.push(nums[i])
        if i-k+1>=0:
            ans.append(mq.max())

            if mq.max()==nums[i-k+1]: #why need this step?
                mq.pop()
    return ans

nums=[1, 3, -1, -3, 5, 3, 6, 7]
k=3

print(maxSlidingWindow(nums,k))
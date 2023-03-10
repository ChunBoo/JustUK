class Solution(object):
    def pickGifts(self, gifts, k):
        """
        :type gifts: List[int]
        :type k: int
        :rtype: int
        """
        a=[-i for i in gifts]
        heapify(a)

        for _ in range(k):
            v=-heappop(a)
            heappush(a,-int(sqrt(v)))
        return -sum(a)
       
        # for _ in range(k):
        #     mx=max(gifts)
        #     i=gifts.index(mx)
        #     gifts[i]=int(sqrt(mx))
        # return sum(gifts)

        # for i in range(k):
        #     gifts.sort()
        #     gifts[-1]=int(sqrt(gifts[-1]))
        
        # # print(gifts)
        # return sum(gifts)
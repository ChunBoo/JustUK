from collections import defaultdict
from math import sqrt
class Solution(object):
    def validSquare(self, p1, p2, p3, p4):
        """
        :type p1: List[int]
        :type p2: List[int]
        :type p3: List[int]
        :type p4: List[int]
        :rtype: bool
        """
        d=defaultdict(int)        
        def dis(p1,p2):
            return sqrt((p2[0]-p1[0])**2+((p2[1]-p1[1])**2))
        arr=[p1,p2,p3,p4]
        for i in range(4):
            for j in range(i):
                dd=dis(arr[i],arr[j])
                d[dd]+=1
        for k,v in d.items():
            print(k,v)
        print("length= ",len(d))
        # print(d[0])   #seems d[0] will create new key
        return len(d)==2 and d[0]==0
    
p1 = [0,0]
p2 = [1,1]
p3 = [1,0]
p4 = [0,1]

print(Solution().validSquare(p1,p2,p3,p4))
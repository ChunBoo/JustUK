
from bisect import bisect_left,bisect_right
from collections import OrderedDict
class CCalendar:
    def __init__(self):
        self.booked=[]
    def book(self,start,end):
        for v in self.booked:
            if max(v[0],start)<min(v[1],end):
                return False
        
        self.booked.append((start,end))
        return True

class CCalendar2:
    def __init__(self):
        self.map=OrderedDict()

    def book(self,start,end):  #https://stackoverflow.com/questions/62731393/using-bisect-left-on-dict-raising-dict-is-not-a-sequence-error-how-to-t
        for k,v in self.map.items():
            if k>=start and v<=end:
                return False
            if 

        return True


v1=[10, 20]
v2=[15, 25]
v3=[20, 30]

cal=CCalendar2()
print(cal.book(v1[0],v1[1]))
print(cal.book(v2[0],v2[1]))
print(cal.book(v3[0],v3[1]))

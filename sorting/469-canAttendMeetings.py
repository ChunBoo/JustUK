'''
 an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false

Example 2:
Input: intervals = [[7,10],[2,4]]
Output: true
'''
def canAttendMeeting(m):
    n=len(m)
    def overlap(a,b):
        return min(a[1],b[1])>max(a[0],b[0])
    for i in range(n):
        for j in range(i):
            if overlap(m[i],m[j]):
                return False
    return True
    
def canAttend(m):
    n=len(m)
    m.sort(key=lambda x:x[0])
    return all(m[i][1]<=m[i+1][0] for i in range(n-1))


def canAttend1(m):
    n=len(m)
    m.sort(key=lambda x:x[0])
    for i in range(n-1):
        if m[i][1]>m[i+1][0]:
            return False
    return True

def canAttend2(m):
    n=len(m)
    sorted(m,key=lambda x:x[1])  #can not work
    for i in range(n-1):
        if m[i][1]>m[i+1][0]:
            return False
    return True

intervals1 = [[0,30],[5,10],[15,20]]
intervals = [[7,10],[2,4]]
print(canAttend(intervals))
# L=[('a', 1), ('b', 12), ('c', 3), ('d', 4)]
# #3、利用参数 key 排序
# sorted(L, key=lambda x:x[1])
# print(L)
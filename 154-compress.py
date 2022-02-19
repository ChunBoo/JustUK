from itertools import groupby


def compress(s):
    return "".join([x for x,y in groupby(s)])

res=compress("aabbbcddeeee")
# print(res)
for x,y in groupby("aabbbcdee"):
    print(x,y)
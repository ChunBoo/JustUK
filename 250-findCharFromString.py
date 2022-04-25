def find(s,t):
    if type(s)!=str:
        raise Exception("s is not string")
    for i,r in enumerate(s):
        if r==t:
            return i
    return -1

print(find("ABC",'D'))
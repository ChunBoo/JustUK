

def isDividedBy3(s):
    total=0
    for i in s:
        total+=int(i)
    return total%3==0

s="12345"
print(isDividedBy3(s))
    


def getOnes(n):
    # if n<=0:
    #     return 0
    str=bin(n)[2:]
    array=str.split("0")
    return max(len(x) for x in array)


print(getOnes(7))



def steps(n):
    b=bin(n)[2:]
    ones=b.count("1")
    zeros=len(b)-ones
    return ones*2+zeros-1


print(steps(15))
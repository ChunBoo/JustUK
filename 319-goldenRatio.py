"""
      DP method for calculating the golden ratio likes fibonacci
"""
def goldenRatio(n):
    a,b=1,1
    for _ in range(n):
        a,b=b,a+b
        print(1.0*b/a)
    return 1.0*b/a

print(goldenRatio(1000))
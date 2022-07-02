def goldenRatio(n):
    
    a,b=1,1
    for _ in range(n):
        a,b=b,a+b
        print(b*1.0/a)
    return b*1.0/a

print(goldenRatio(1000))

    
def knapsackVariantMultipleCOinsToss(prob,target):
    n=len(prob)
    if target>n:
        return 0
    
    def f(i,h):
        if i==len(prob):
            return 1 if h==0 else 0
        choose=prob[i]*f(i+1,h-1)
        skip=(1-prob[i])*f(i+1,h)
        return choose+skip
    
    return f(0,target)

prob = [0.5,0.5,0.5,0.5,0.5]
target = 0
print(knapsackVariantMultipleCOinsToss(prob,target))
        
#lambda function of python

from functools import reduce

def finalValue(ops):
    return reduce(lambda a,b: a+1 if b[1]=='+' else a-1,ops,0 )
    

ops=['++','--','++']
print(finalValue(ops))
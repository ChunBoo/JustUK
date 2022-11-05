"""
  immutable types: int/float/string/tuple/frozenset/bytes/comples
  mutable types:list/dictionary/set
"""

y=(1,2,3)
x=[1,2,3]
v=1
# s=set(1,2,3)
def f():
    global v  #pass the reference now
    v=2
f()
print(v)
def fPassByValue(x):
    x.append(4)
def fPassByReference(y):
    y=(4,5,6)
fPassByValue(x)
print(x)
fPassByReference(x)
print(x)
# 
# f(y)
# print(y)
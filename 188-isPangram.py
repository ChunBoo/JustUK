from collections import Counter
from pydoc import ispackage
def isPangram(words):
    c=Counter(words)
    return len(c)==27

s="the quick brown fox jump over the lazy dogs"
print(isPangram(s))
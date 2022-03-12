from collections import Counter

def isPangram(words):
    c=Counter(words)
    return len(c)==27  #contains the space

s="the quick brown fox jump over the lazy dogs"
print(isPangram(s))
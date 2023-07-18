
from collections import defaultdict
def prefixAndSuffix(words, pref,suff):
    d=defaultdict()
    index=0

    for word in words:
        _n=len(word)
        prefixes,suffixes=[""]*(_n+1),[""]*(_n+1)
        for i in range(_n):
            prefixes[i+1]=prefixes[i]+word[i]
            suffixes[i+1]=word[_n-i-1]+suffixes[i]
        
        for p in prefixes:
            for s in suffixes:
                key=p+"_"+s
                d[key]=index
        index+=1
    
    pf=pref+"_"+suff
    if pf in d:
        return d[pf]
    return -1


print(prefixAndSuffix(["apple","abcdef"],"a","e"))
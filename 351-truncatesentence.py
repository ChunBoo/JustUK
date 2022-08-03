

def truncateSentence(s,k):
    if k<0:
        return ""
    a=s.split(',')
    return " ".join(a[:min(k,len(a))])


s="Hello,A,Hi,B"
print(truncateSentence(s, 3))
    
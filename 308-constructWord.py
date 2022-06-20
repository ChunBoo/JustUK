def constructWord(rules):
    data=set()
    for rule in rules:
        a,b=rule.split(">")
        data.add(a)
        data.add(b)
    
    m={}
    for rule in rules:
        a,b=rule.split(">")
        m[a]=b
        data.remove(b)
    
    cur=list(data)[0]
    ans=cur
    while cur in m:
        ans+=m[cur]
        cur=m[cur]
    return ans

rules=["E>R","R>I","I>C"]
print(constructWord(rules))
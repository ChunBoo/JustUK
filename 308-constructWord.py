def constructWord(rules):
    s=set()
    m={}
    ans=""
    for rule in rules:
        a,b=rule.split(">")
        s.add(a)
        s.add(b)
        
    for rule in rules:
        a,b=rule.split(">")
        s.remove(b)
        m[a]=b
    
    cur=list(s)[0]
    ans+=cur
    while cur in m:
        ans+=m[cur]
        cur=m[cur]
    
    return ans

rules=["E>R","R>I","I>C"]
print(constructWord(rules))
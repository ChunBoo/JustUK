




def flightsList(flights):
    if not flights:
        return []
    
    G={a:b for a,b in flights}
    s=set(G.keys())-set(G.values())
    start=next(iter(s))
    ans=[next(iter(s))]
    
    while start in G:
        start=G[start]
        ans.append(start)
        
    return ans


flights=[['a','b'],['b','c'],['c','d']]
print(flightsList(flights))
'''
given a list of flights that were taken, represented as origin to destination airport pairs. Given that this list was shuffled, 
find all the airports that were visited in the correct order. Note: you can assume that no airport was visited twice.

Constraints
n ≤ 100,000 where n is the length of flights
Example 1
Input

1
2
3
4
5
flights = [
    ["WRE", "RPM"],
    ["AGN", "WRE"],
    ["NTL", "AGN"]
]
Output

1
["NTL", "AGN", "WRE", "RPM"]
Explanation
The only way to have taken the 3 flights was to have taken “NTL” -> “AGN” first. After that, “AGN” -> “WRE”, and “WRE” -> “RPM” could be taken.
Can you relate this with topological sort?

Try finding the airport with indegree 0. That will be the starting point of the route.
'''


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
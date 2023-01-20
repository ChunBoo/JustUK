# https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
'''
given a two-dimensional list of integers ports where ports[i] represents the list of ports that port i is connected to. You are also given another two-dimensional list of integers shipments where each list of the form [port_i, port_j] which means there is a shipment request from port_i to port_j.

Given that the cost to ship port_i to port_j is the length of the shortest path from the two ports, return the total cost necessary to send all the shipments. If there’s not a path between two ports, the cost is 0.

Constraints
p ≤ 100 where p is the length of ports
s ≤ 10,000 where s is the length of shipments
Example 1
Input

1
2
3
4
5
6
7
8
9
10
ports = [
    [2, 3],
    [2],
    [1, 0],
    [4],
    []
]
shipments = [
    [2, 4]
]
Output
3
'''
from math import inf
def shortestPath(G,paths):
    n=len(G)
    d=[[0 if i==j else inf for i in range(n)] for j in range(n)]
    
    for i,v in enumerate(G):
        for j in v:
            d[i][j]=1
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                d[i][j]=min(d[i][j],d[i][k]+d[k][j])
    return sum(d[i][j] if d[i][j]!=inf else 0 for i,j in paths)


ports = [
    [2, 3],
    [2],
    [1, 0],
    [4],
    []
]
shipments = [
    [2, 4]
]
print(shortestPath(ports,shipments))
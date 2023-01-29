

#BFS/DFS can not be used in weighted graph, as iFloydWarshall 
#https://stackoverflow.com/questions/30409493/using-bfs-for-weighted-graphs

from math import inf

def shortestDistance(dist,s,e):
    n=len(dist)
    d=[[inf]*n for _ in range(n)]
    for i in range(n-1):
        d[i][i+1]=d[i+1][i]=dist[i]
        
    d[0][n-1]=d[n-1][0]=dist[-1]
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                d[i][j]=min(d[i][j],d[i][k]+d[k][j])
                
    return d[s][e]


distance=[1,2,3,4]
start=0
stop=1

print(shortestDistance(distance,start,stop))
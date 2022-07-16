
import math
def shortestDistance(G,n):
    dis=[[math.inf for _ in range(n)] for _ in range(n)]
    for a,b,w in G:
        dis[a][b]=w
    
    for  i in range(n):
        dis[i][i]=0
        
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j])
                
    return dis

G=[(1,2,100),(1,3,10),(3,2,20),(3,4,100)]

res=shortestDistance(G,5)
for i in range(3):
    print(res[i])
        
def networkDelay(times,n,k):
    MAX_TIME=100*100
    dist=[MAX_TIME]*n
    
    dist[k-1]=0  #0-indexed
    
    for i in range(n):
        for time in times:
            u,v,w=time[0]-1,time[1]-1,time[2]
            dist[v]=min(dist[v],dist[u]+w)
    
    ans=max(dist)
    return -1 if ans==MAX_TIME else ans

def networkDelay2(times,n,K):
    MAX_TIME=100*100
    dist=[[MAX_TIME for i in range(n)] for _ in range(n)]
    
    for time in times:
        dist[time[0]-1][time[1]-1]=time[2]
    
    for i in range(n):
        dist[i][i]=0
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    from math import inf
    ans=-inf
    for i in range(n):
        if dist[K-1][i]>=MAX_TIME:  #here can not be use the k as loop variable
            return -1;
        ans=max(ans,dist[K-1][i])
    return ans

times = [[2,1,1],[2,3,1],[3,4,1]]
n = 4
k = 2
print(networkDelay(times,n,k))
print(networkDelay2(times,n,k))
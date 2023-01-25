'''
A bus has n stops numbered from 0 to n - 1 that form a circle. We know the distance between all pairs of neighboring stops where distance[i] is the distance between the stops number i and (i + 1) % n.

The bus goes along both directions i.e. clockwise and counterclockwise.

Return the shortest distance between the given start and destination stops.

'''

def shortestDistance(distance,start,stop):
    if start>stop:
        start,stop=stop,start
    
    d1=sum(distance[start:stop])
    # d2=sum(distance)-d1
    d2=sum(distance[:start])+sum(distance[stop:])
    return min(d1,d2)

distance=[11,2,3,4]
start=0
stop=1

print(shortestDistance(distance,start,stop))
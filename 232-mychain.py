def chain(a):
    for i in a:
        for j in i:
            yield j
            
            
l=[[1,2,3],[4,5],[6]]
print(list(chain(l)))
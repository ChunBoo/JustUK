def move(n,src,dest,tmp):
    if n==1:
        print("Move disk 1 from", src," to", dest)
        return 
    move(n-1,src,tmp,dest)
    print("move disk:",n,"from",src,"to", dest)
    move(n-1,tmp,dest,src)
    
move(3,"src","dest","tmp")
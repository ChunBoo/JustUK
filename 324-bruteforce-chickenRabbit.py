def chickensAndRabbits(H,L):
    if H<1 or L<1:
        return None
    
    for c in range(H+1):
        r=H-c
        if(4*r+2*c==L):
            return (c,r)
        


print(chickensAndRabbits(10, 24))
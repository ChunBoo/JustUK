def trans(m):
    R=len(m)
    for r in range(R):
        for c in range(r):
            m[r][c],m[c][r]=m[c][r],m[r][c]


m=[[1,2,3],
   [4,5,6],
   [7,8,9]]
trans(m)
for _ in m:
    print(_)


def rangeSumQurey(nums,r1,c1,r2,c2):
    if not nums:
        return ;
    r,c=len(nums),len(nums[0])
    sums=[[0]*(c+1)]*(m+1)

    for i in range(1,r+1):
        for j in range(1,c+1):
            sums[i][j]=nums[i-1][j-1]+ sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]
    
    return sums[r2+1][c2+1]-sums[r1+1][c2]-sums[r2][c1]+sums[r1][c1]
    
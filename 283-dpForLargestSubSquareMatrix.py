def largestSubSquareMatrix(M):
    R,C=len(M),len(M[0])
    dp=[[0 for _ in range(C)] for _ in range(R)]
    ans=0
    
    for  r in range(R):
        for c in range(C):
            if M[r][c]==0:
                dp[r][c]=0
            else:
                if r>0 and c>0 and M[r-1][c]==1 and M[r][c-1]==1 and \
                    M[r-1][c-1]==1:
                        dp[r][c]=min(dp[r-1][c-1],dp[r][c-1],dp[r-1][c])+1;
            ans=max(ans,dp[r][c]);
    return ans*ans

m=[[1,1,0,0],\
   [1,1,0,1],\
   [1,1,1,0],\
   [1,1,1,0],\
   [1,1,1,0]]

print(largestSubSquareMatrix(m))


def champagneTower(poured, queryRow,queryGlass):
    kRows=100
    dp=[[0.0 for _ in range(kRows)] for _ in range(kRows)]
    # dp=[[0.0 for _ in range(kRows)]]*(kRows)  #can not work, reason is https://stackoverflow.com/questions/240178/list-of-lists-changes-reflected-across-sublists-unexpectedly

    dp[0][0]=poured
    print(f"len(dp):{len(dp)}")
    print(f"len(dp[0]):{len(dp[0])}")
    for i in range(kRows):
        for j in range(i+1):
            if dp[i][j]>1:
                dp[i+1][j]+=(dp[i][j]-1)/2.0
                dp[i+1][j+1]+=(dp[i][j]-1)/2.0
    return min(1.0,dp[queryRow][queryGlass])


print(champagneTower(4,2,1))
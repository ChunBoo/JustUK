

def champagneTower(poured, queryRow,queryGlass):
    kRows=100
    dp=[[0.0 for _ in range(kRows+1)] for _ in range(kRows+1)]
    # dp=[[0.0 for _ in range(kRows)]]*(kRows)  #can not work, reason is https://stackoverflow.com/questions/240178/list-of-lists-changes-reflected-across-sublists-unexpectedly

    dp[0][0]=poured
    print(f"len(dp):{len(dp)}")
    print(f"len(dp[0]):{len(dp[0])}")
    for i in range(kRows):
        
        for j in range(i+1):
            if i==99:
                print(99)
            if dp[i][j]>1:
                dp[i+1][j]+=(dp[i][j]-1)/2.0
                dp[i+1][j+1]+=(dp[i][j]-1)/2.0
    return min(1.0,dp[queryRow][queryGlass])

poured = 100000009
query_row = 99
query_glass = 17
print(champagneTower(poured,query_row,query_glass))
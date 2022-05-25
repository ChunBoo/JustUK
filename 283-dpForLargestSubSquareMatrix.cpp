#include<iostream>
#include<vector>
#include<algorithm>
using DT=std::vector<std::vector<int>>;
int largestSubSquareMatrix(const DT& M)
{
    int R=M.size(),C=M[0].size(),ans=0;
    DT dp(R,std::vector<int>(C,0));
    for(int r=0;r<R;++r)
    {
        for(int c=0;c<C;++c)
        {
            if(M[r][c]==0)
                dp[r][c]=0;
            else
            {   

                if(r>0&&c>0&&M[r][c-1]==1&&M[r-1][c]==1&&M[r-1][c-1]==1)
                {
                    dp[r][c]=std::min(dp[r][c-1],dp[r-1][c-1],dp[r-1][c])+1;
                }
            }
            ans=std::max(ans,dp[r][c]);
        }
    }
    return ans*ans;
}

int main()
{
    DT M{{1,1,0,0,0},\
         {1,1,1,0,0},\
         {1,1,1,0,0},\
         {1,1,1,0,0}};
    std::cout<<largestSubSquareMatrix(M);
}
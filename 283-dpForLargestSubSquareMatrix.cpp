//DP method for getting the largest subsquare matrix
#include<iostream>
#include<vector>
#include<algorithm>
using DT=std::vector<std::vector<int>>;
// Defining the binary function

bool comp(int a, int b)
{
    return (a <b);
}
int largestSubSquareMatrix(const DT& M)
{
    int ans=0,R=M.size(),C=M[0].size();
    DT dp(R,std::vector<int>(C,0));
    for(int r=0;r<R;++r)
    {
        for(int c=0;c<C;++c)
        {
            if(M[r][c]==0)
                dp[r][c]=0;
            else
            {
                dp[r][c]=1;
                if(r>0&&c>0&&M[r-1][c-1]==1&&M[r][c-1]==1&&M[r-1][c]==1)
                {
                    dp[r][c]=std::min({dp[r-1][c-1],dp[r][c-1],dp[r-1][c]})+1;
                }
            }
            ans=std::max(ans,dp[r][c]);
        }
    }
    return  ans*ans;
}

int main()
{
    DT M{{1,1,0,0,0},\
         {1,1,1,0,0},\
         {1,1,1,0,0},\
         {1,1,1,0,0}};
    std::cout<<largestSubSquareMatrix(M);
    std::cout<<std::min({1,2,3,-1},comp);
    std::cout<<std::max({1,2,3,-1});

}
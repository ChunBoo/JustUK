#include<iostream>
#include<vector>
#include<cmath>
using DT=std::vector<std::vector<int>>;
int dfs(int r,int c,int R,int C, DT& m)
{

    if(r>=R||c>=C||r<0||c<0)
        return 0;
    if(m[r][c]==0)
        return 0;
    int ans=1;
    m[r][c]=0;
    ans+=dfs(r-1,c,R,C,m)+dfs(r+1,c,R,C,m)+dfs(r,c-1,R,C,m)+dfs(r,c+1,R,C,m);
    return ans;
}


int maxIslands( DT& m)
{
    int R=m.size();
    int C=m[0].size();
    if(R==0||C==0)
        return 0;
    int ans=0;
    for(int r=0;r<R;++r)
    {
        for(int c=0;c<C;++c)
        {
            ans=std::max(dfs(r,c,R,C,m),ans);
        }
    }
    return ans;
}

int main()
{
    DT M={{1,1,1,0},\
          {1,1,0,0},\
          {0,0,1,1},\
          {1,0,0,0}};
    std::cout<<maxIslands(M);
    return 0;
}
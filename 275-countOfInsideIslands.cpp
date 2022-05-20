#include<vector>
#include<iostream>

using DT=std::vector<std::vector<int>>;

void dfs(DT& m,int r,int c,int R,int C)
{
    if(r<0||c<0||r>=R||c>=C)
        return ;
    if(m[r][c])
    {
        m[r][c]=0;
        dfs(m,r,c-1,R,C);
        dfs(m,r,c+1,R,C);
        dfs(m,r+1,c,R,C);
        dfs(m,r-1,c,R,C);
    }
}


int countOfInsidedIslands(DT& m)
{
    if(m.empty())
        return 0;
    
    int R=m.size(),C=m[0].size();
    //clear the border
    for(int r=0;r<R;++r)
    {
        dfs(m,r,0,R,C);
        dfs(m,r,C-1,R,C);
    }
    for(int c=0;c<C;++c)
    {
        dfs(m,0,c,R,C);
        dfs(m,R-1,c,R,C);
    }
    //count the insided islands
    int ans=0;
    for(int r=1;r<R;++r)
    {
        for(int c=1;c<C;++c)
        {
            if(m[r][c])
            {
                ans+=1;
                dfs(m,r,c,R,C);
            }
        }
    }
    return ans;
}

int main()
{
    DT m{{1,0,0,0,1},
         {0,1,0,1,0},
         {0,0,1,0,0},
         {1,0,0,0,1}
        };
    std::cout<<countOfInsidedIslands(m);   
    return 0;
}
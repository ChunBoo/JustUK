#include<iostream>
#include<vector>

using DT=std::vector<std::vector<int>>;
int  islandPerimeter(DT& m)
{
    int R=m.size(),C=m[0].size();
    if(R==0||C==0)
        return 0;
    int ans=0;

    for(int r=0;r<R;++r)
    {
        for(int c=0;c<C;++c)
        {
            if(m[r][c]==1)
            {
                ans+=4;
                if(r>0 && m[r-1][c]==1)
                    ans-=2;
                if(c>0&& m[r][c-1]==1)
                    ans-=2;
            }
        }
    }
    return ans;
}

int main()
{
    DT m{{1,0,0},{1,1,0},{0,0,1}};
    std::cout<<islandPerimeter(m);
    return 0;
}


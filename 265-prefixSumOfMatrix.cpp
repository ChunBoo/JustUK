#include<vector>
#include<iostream>

using DT=std::vector<std::vector<int>>;

DT prefixSumOfMatrix(DT& m)
{
    int R=m.size(),C=m[0].size();
    if(R==0||C==0)
        return m;
    for(int r=0;r<R;++r)
    {
        for(int c=1;c<C;++c)
        {
            m[r][c]+=m[r][c-1];
        }
    }
    for(int r=1;r<R;++r)
    {
        for(int c=0;c<C;++c)
        {
            m[r][c]+=m[r-1][c];
        }
    }
    return m;
}

int main()
{
    DT m{{0,1,2},{2,1,4},{3,2,1}};
    DT M=prefixSumOfMatrix(m);
    for(auto r:M)
    {   
        std::cout<<'\n';
        for(auto v:r)
            std::cout<<v<<',';
    }
    return 0;
}
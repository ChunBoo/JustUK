#include<iostream>
#include<vector>
#include<map>

using MATRIX=std::vector<std::vector<int>>;
using MAP=std::map<int,int>;

void f(int r,int c,int color, MATRIX& m)
{
    int R=m.size(),C=m[0].size();
    if(r<0||r>=R||c<0||c>=C)
        return ;
    if(m[r][c]!=color)
        return ;
    m[r][c]=-1;
    f(r+1,c,color,m);
    f(r-1,c,color,m);
    f(r,c+1,color,m);
    f(r,c-1,color,m);
}

int steps(MATRIX& m)
{
    MAP data{};
    int R=m.size(),C=m[0].size();
    for(int r=0;r<R;++r)
    {
        for(int c=0;c<C;++c)
        {
            if(m[r][c]!=-1)
            {
                int color=m[r][c];
                f(r,c,color,m);
                data[color]+=1;
            }
        }
    }
    int _max=0;
    int _sum=0;
    for(auto &[k,v]:data)
    {
        _sum+=v;
        if(v>_max)
            _max=v;
    }
    return _sum-_max;
}

int main()
{
    MATRIX m{
    {1, 1, 1, 1},
    {2, 2, 2, 2},
    {1, 3, 1, 2}};
    std::cout<<steps(m);
}
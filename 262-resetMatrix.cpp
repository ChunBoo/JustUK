//reset matrix

#include<set>
#include<vector>
#include<iostream>

using DT=std::vector<std::vector<int>>;
void resetMatrix(DT& m)
{
    int R=m.size(),C=m[0].size();
    std::set<int> rs{},cs{};
    for(int r=0;r<R;++r)
    {
        for(int c=0;c<C;++c)
        {
            if(m[r][c]==0)
            {
                rs.insert(r);
                cs.insert(c);
            }
        }
    }
    for(int r=0;r<R;++r)
    {
        for(int c=0;c<C;++c)
        {
            if(rs.find(r)!=rs.end()||cs.find(c)!=cs.end())
                m[r][c]=0;
        }
    }
}
int main()
{
    DT m{{0,0,1},{1,0,1},{1,1,1}};
    resetMatrix(m);
    for(auto r:m)
    {
        std::cout<<'\n';
        for(auto v:r)
            std::cout<<v<<',';
    }
    return 0;
}
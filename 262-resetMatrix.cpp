//reset matrix,used one set to record all positions of 0 in original matrix

#include<set>
#include<vector>
#include<iostream>

using DT=std::vector<std::vector<int>>;
void resetMatrix(DT& m)
{
    int R=m.size(),C=m[0].size();
    std::set<int> seen{};
    for(int r=0;r<R;++r)
    {
        for(int c=0;c<C;++c)
        {
            if(m[r][c]==0)
                seen.insert(r);
        }
    }

    for(int r=0;r<R;++r)
    {
        for(int c=0;c<C;++c)
        {
            if(seen.find(r)!=seen.end() || seen.find(c)!=seen.end())
                m[r][c]=0;
        }
    }
}
int main()
{
    DT m{{1,1,1},{1,0,1},{1,1,1}};
    resetMatrix(m);
    for(auto r:m)
    {
        std::cout<<'\n';
        for(auto v:r)
            std::cout<<v<<',';
    }
    return 0;
}
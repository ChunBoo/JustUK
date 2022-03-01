//given a matrix,which just has 0 and 1,from left to right,and from top to bottom
/*
    0 0 0 1
    0 1 1 1
    0 1 1 1
*/
#include<vector>
#include<iostream>
using MATRIX=std::vector<std::vector<int>>;
using VEC=std::vector<int>;
int findTheColWhichHasFirstOne(const MATRIX& m)
{
    if(m.empty())
        return -1;
    int R=m.size();
    int C=m[0].size();
    int r=0,c=C-1;
    int ans=-1;
    while(r<R&&c>=0)
    {
        if(m[r][c]==1)
        {
            ans=c;
            c-=1;
        }
        else
            r+=1;
    }
    return ans;
}

int main()
{
    MATRIX m{{0,0,0,1},{0,0,1,1},{0,0,1,1},{0,0,1,1}};
    std::cout<<findTheColWhichHasFirstOne(m)<<'\n';
    return 0;
}
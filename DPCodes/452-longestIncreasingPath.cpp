#include<iostream>
#include<vector>

using MATRIX=std::vector<std::vector<int>>;


int f(int r,int c,int R,int C,const MATRIX& m)
{
    int ans=1;
    MATRIX D{{1,0},{-1,0},{0,1},{0,-1}};
    for(auto &v:D)
    {
        int nr=v[0]+r;
        int nc=v[1]+c;
        if(nr>=0 &&nr<R &&nc>=0 &&nc<C&&(m[r][c]<m[nr][nc]))
        {
            ans=std::max(ans,f(nr,nc,R,C,m)+1);
        }
    }
    return ans;
}
int longestIncreasingPath(const MATRIX& m)
{
    int R=m.size(), C=m[0].size();
    if(R==0 || C==0)
        return 0;
    int ans=1;
    for(int r=0;r<R;++r)
    {
        for(int c=0;c<C;++c)
        {
            ans=std::max(ans,f(r,c,R,C,m));
        }
    }
    return ans;
}

int main()
{
    MATRIX m {
    {1, 3, 5},
    {0, 4, 6},
    {2, 2, 9}
    };
    std::cout<<longestIncreasingPath(m);
}
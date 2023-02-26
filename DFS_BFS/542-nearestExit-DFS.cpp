#include<iostream>
#include<set>
#include<vector>

using std::cout;
using VEC=std::vector<char>;
using VEC_INT=std::vector<int>;
using MATRIX=std::vector<VEC>;

bool isExit(int r,int c,const MATRIX& m)
{
    int rows=m.size();
    int cols=m[0].size();
    if(r==0||c==0 ||r==rows-1||c==cols-1)
        return m[r][c]=='.';
    return false;
}

void dfs(const MATRIX& m,int r, int c,int d,std::set<VEC_INT>& seen,int &ans,const VEC_INT& entry)
{
    int rows=m.size();
    int cols=m[0].size();
    if(VEC_INT(r,c)!=entry &&(isExit(r,c,m)))
    {
        ans=std::min(ans,d);
        return ;
    }
    if(seen.find(VEC_INT(r,c))!=seen.end())
        return ;
    seen.insert(VEC_INT(r,c));
    std::vector<VEC_INT> dirs{{1,0},{0,1},{-1,0},{0,-1}};
    for(auto &dir:dirs)
    {
        int nr=dir[0]+r;
        int nc=dir[1]+c;
        if(nr>=0 &&nr<rows &&nc>=0 &&nc<cols &&m[nr][nc]=='.')
        {
            dfs(m,nr,nc,d+1,seen,ans,entry);
        }
    }
    seen.erase(VEC_INT(r,c));
}


int nearestExit(const MATRIX& m,  const VEC_INT& entry)
{
    int ans=INT_MAX;
    std::set<VEC_INT> seen{};
    dfs(m,entry[0],entry[1],0,seen,ans,entry);
    return ans!=INT_MAX?ans:-1;
}

int main()
{
    // maze = [['+','+','.','+'],['.','.','.','+'],['+','+','+','.']]
// entrance = [1,2]

    MATRIX m{{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
    VEC_INT entrance{1,2};
    cout<<nearestExit(m,entrance);
}
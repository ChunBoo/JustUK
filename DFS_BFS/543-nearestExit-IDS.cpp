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


bool DLS(MATRIX& m,int r,int c,int d,const VEC_INT& entry)
{
    int rows=m.size();
    int cols=m[0].size();

    if(VEC_INT(r,c)!=entry && isExit(r,c,m))
        return true;

    if(d<=0)
        return false;
    m[r][c]='+';
    std::vector<VEC_INT> dirs{{1,0},{0,1},{-1,0},{0,-1}};

    for(auto &dir:dirs)
    {
        int nr=r+dir[0];
        int nc=c+dir[1];
        if(nr>=0 &&nr<rows &&nc>=0 &&nc<cols &&m[nr][nc]=='.')
        {
            if( DLS(m,nr,nc,d-1,entry))
                return true;
        }
    }
    m[r][c]='.';
}

int nearestExit( MATRIX& m,  const VEC_INT& entry)
{
    int d=0;
    int D=m[0].size()*m.size();
    while(d<D)
    {
        if(DLS(m,entry[0],entry[1],d,entry))
            return d;
        d+=1;
    }
    return -1;
}


int main()
{
        // maze = [['+','+','.','+'],['.','.','.','+'],['+','+','+','.']]
// entrance = [1,2]

    MATRIX m{{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
    VEC_INT entrance{1,2};
    cout<<nearestExit(m,entrance);
}

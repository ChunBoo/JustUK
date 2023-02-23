#include<iostream>
#include<deque>
#include<set>
#include<vector>


using std::cout;
using VEC=std::vector<char>;
using VEC_INT=std::vector<int>;
using MATRIX=std::vector<VEC>;


bool isExit(const MATRIX& m,int r,int c)
{
    int rows=m.size();
    int cols=m[0].size();
    if(r==0 ||c==0 ||(r==rows-1)||(c==cols-1))
        return m[r][c]=='.';
    return false;
}


int nearestExit(const MATRIX& m,VEC_INT entry)
{
    std::deque<std::pair<VEC_INT,int>> q{};
    q.push_back(std::make_pair(entry,0));
    std::set<VEC_INT> seen{};
    int rows=m.size();
    int cols=m[0].size();
    while(!q.empty())
    {
        std::pair<VEC_INT,int> cur=q.front();
        q.pop_front();
        VEC_INT pos=cur.first;
        int d=cur.second;

        if(isExit(m,pos[0],pos[1])&&(entry!=pos))
            return d;
        
        std::vector<VEC_INT> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        for( auto &dir:dirs)
        {
            int nr=pos[0]+dir[0];
            int nc=pos[1]+dir[1];
            VEC_INT tmp{nr,nc};
            if((seen.find(tmp)!=seen.end())||(nr<0) ||(nc<0)||(nr>=rows-1)||(nc>=cols-1))
                continue;
            if(m[nr][nc]=='.')
            {
                seen.insert(tmp);
                q.push_back(std::make_pair(tmp,d+1));  //seems make_pair can not work for anonymous object
            }
        }
        
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
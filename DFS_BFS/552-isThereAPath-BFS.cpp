#include<iostream>
#include<deque>
#include<vector>
#include<set>
#include<utility>
using std::cout;
using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;
using Q=std::deque<std::pair<VEC,int>>;

bool isThereAPath(const MATRIX& m)
{
    int rows=m.size();
    int cols=m[0].size();
    int balance=0;
    std::set<VEC> seen;
    Q q{};
    VEC tmp{0,0};
    q.push_back(std::make_pair(tmp,balance));
    while(!q.empty())
    {
        std::pair<VEC,int> cur=q.front();
        q.pop_front();
        int r=cur.first[0],c=cur.first[1];
        int b=cur.second;
        // b+=(m[r][c]==1?1:-1);
        if(m[r][c]==1)
            b+=1;
        else
            b-=1;
        if((r==rows-1)&&(c==cols-1))
        {
            if(b==0)
                return true;
        }
        VEC t{r,c};
        if(seen.find(t)!=seen.end())
            continue;
        seen.insert(t);
        MATRIX dirs{{0,1},{1,0}};
        for(auto &d:dirs)
        {
            int nr=d[0]+r,nc=d[1]+c;
            if((nr>=0)&&(nr<rows)&&(nc>=0)&&(nc<cols))
            {
                VEC tt{nr,nc};
                q.push_back(std::make_pair(tt,b));
            }
        }
    }
    return false;
}

int main()
{
    MATRIX grid{{{0,1,0,0},{0,1,0,0},{1,0,1,0}}};
    cout<<isThereAPath(grid);
}
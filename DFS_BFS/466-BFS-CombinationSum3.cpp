#include<vector>
#include<iostream>
#include<deque>
#include<numeric>
using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;
using PAIR=std::pair<VEC,int>;
using Q=std::deque<PAIR>;

MATRIX combineSum(int k,int n)
{
    MATRIX m{};
    if(k>9 || n>45)
        return m;
    VEC cur{};
    Q q{PAIR(cur,1)};
    while(!q.empty())
    {
        int sz=q.size();
        for(int _=0;_<sz;++_)
        {
            VEC t=q.front().first;
            int x=q.front().second;
            q.pop_front();
            if(t.size()==k && std::accumulate(t.begin(),t.end(),0)==n)
                m.push_back(t);
            else if(t.size()<k && std::accumulate(t.begin(),t.end(),0)<n)
            {
                for(int i=x;i<10;++i)
                {
                    VEC tt{t.begin(),t.end()};
                    tt.push_back(i+1);
                    q.push_back(PAIR(tt,i+1));
                }
            }
        }
    }
    return m;
}

int main()
{
    MATRIX ans=combineSum(3,9);
    for(auto &v:ans)
    {
        std::cout<<'\n';
        for(auto &d:v)
            std::cout<<d<<',';
    }
}
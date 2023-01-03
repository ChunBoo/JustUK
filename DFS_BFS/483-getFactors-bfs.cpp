#include<vector>
#include<iostream>
#include<deque>
#include<vector>
#include<cmath>
using VEC=std::vector<int>;
using PAIR=std::pair<std::pair<int,int>,VEC>;
using MATRIX=std::vector<std::vector<int>>;


MATRIX getFactors(int n)
{
    MATRIX ans{};
    std::deque<PAIR> q{PAIR(std::pair<int,int>(n,2),VEC{})};
    while(!q.empty())
    {
        PAIR tmp=q.front();
        int num=tmp.first.first;
        int last=tmp.first.second;
        VEC cur=tmp.second;
        q.pop_front();
        for(int i=last;i<int(std::sqrt(n))+1;++i)
        {
            if((num%i)==0)
            {
                VEC temp{cur};
                temp.push_back(i);
                temp.push_back(num/i);
                ans.push_back(temp);
                temp.pop_back();
                PAIR tPair{PAIR(std::pair<int,int>(num/i,i),temp)};
                q.push_back(tPair);
            }
        }
    }
    return ans;
}
int main()
{
    MATRIX res=getFactors(12);
    for(auto &v:res)
    {
        for(auto &d:v)
        {
            std::cout<<d<<',';
        }
        std::cout<<'\n';
    }
}
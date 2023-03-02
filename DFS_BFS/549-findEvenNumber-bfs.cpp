#include<iostream>
#include<set>
#include<vector>
#include<deque>
#include<map>

using std::cout;
using VEC=std::vector<int>;
using MAP=std::map<int,int>;
using SET=std::set<int>;


MAP myCounter(const VEC& digits)
{
    MAP ans{};
    for(auto &i:digits)
    {
        ans[i]+=1;
    }
    return ans;
}

SET findEvenNumbers(const VEC& digits)
{
    MAP C=myCounter(digits);
    SET ans{};
    std::deque<std::pair<int,MAP>> q{};
    std::pair<int,MAP> p(0,C);
    q.push_back(p);
    while(!q.empty())
    {
        std::pair cur=q.front();
        q.pop_front();
        int x=cur.first;
        MAP c=cur.second;
        if(x>99)
        {
            if((x&1)==0)
                ans.insert(x);
        }
        else
            for(int i=0;i<10;++i)
            {
                if(c[i]>0)
                {
                    MAP cc{c};
                    cc[i]-=1;
                    std::pair<int,MAP> tmp{x*10+i,cc};
                    q.push_back(tmp);
                }
            }
    }
    return ans;
}


int main()
{
    VEC nums{1,2,3,0};
    SET res{findEvenNumbers(nums)};
    for(auto i:res)
        cout<<i<<',';
}
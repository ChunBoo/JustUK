#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
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

void dfoo(SET& ans,int x,MAP& c)
{
    if(x>99)
    {
        if((x&1)==0)
            ans.insert(x);
        return;
    }
    for(int i=0;i<10;++i)
    {
        if(c[i]>0)
        {
            c[i]-=1;
            dfoo(ans,x*10+i,c);
            c[i]+=1;
        }
    }
}

SET findEvenNumbers(const VEC& digits)
{
    SET ans{};
    MAP c{myCounter(digits)};
    dfoo(ans,0,c);
    return ans;
}

int main()
{
    VEC nums{1,2,3,0};
    SET res{findEvenNumbers(nums)};
    for(auto i:res)
        cout<<i<<',';
}
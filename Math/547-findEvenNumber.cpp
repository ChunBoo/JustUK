#include<iostream>
#include<vector>
#include<map>

using std::cout;
using VEC=std::vector<int>;
using MAP=std::map<int,int>;

MAP myCounter(const VEC& nums)
{
    MAP ans{};
    for(auto &i:nums)
        ans[i]+=1;
    return ans;
}

VEC findEvenNumbers(const VEC& digits)
{
    VEC ans{};
    MAP total{myCounter(digits)};

    for(int i=100;i<999;i+=2)
    {
        VEC tmp{i/100,(i/10)%10,i%10};
        MAP m{myCounter(tmp)};
        bool isCovered=true;
        for(auto &[k,v]:m)
        {
            if(v>total[k])
                isCovered=false;
        }
        if(isCovered)
            ans.push_back(i);
    }
    return ans;
}

int main()
{
    VEC nums{2,1,3,0};
    VEC res=findEvenNumbers(nums);
    for(auto &v:res)
        cout<<v<<',';
}
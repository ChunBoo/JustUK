#include<unordered_map>
#include<iostream>
#include<vector>
#include<cmath>
using VEC=std::vector<int>;
using MAP=std::unordered_map<int,int>;

using std::cout;


int longestConsecutiveNumbers(VEC nums)
{
    MAP m{};  //note:here is unordered_map, but not set,which can not be initialized by initialized list
    int ans=0;
    for(auto i:nums)
    {
        if(m.count(i))   //if already has current value in map,then skip it.
            continue;
        auto it_l=m.find(i-1);
        auto it_r=m.find(i+1);

        int l=it_l!=m.end()?it_l->second:0;
        int r=it_r!=m.end()?it_r->second:0;

        int t=l+r+1;
        m[i]=m[i-l]=m[i+r]=t;
        ans=std::max(ans,t);
    }
    return ans;
}

int main()
{
    VEC nums{5,200,1,3,2};
    cout<<longestConsecutiveNumbers(nums);
}
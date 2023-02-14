#include<iostream>
#include<vector>

using VEC=std::vector<int>;
using std::cout;

int gcd(int a,int b)
{
    while(b)
    {
        int tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}

int minSplits(const VEC& nums)
{
    int ans=0;
    int cur=1;
    for(auto &i:nums)
    {
        cur=gcd(i,cur);
        if(cur==1)
        {
            ans+=1;
            cur=i;
        }
    }
    return ans;
}

int main()
{
    VEC nums{12,6,3,13,8};
    cout<<minSplits(nums);
}

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using std::cout;

int foo(int n)
{
    std::vector<int> nums{};
    while(n)
    {
        nums.push_back(n%10);
        n/=10;
    }
    std::sort(nums.begin(),nums.end());
    // std::make_heap(nums.begin(),nums.end());
    int s1=0,s2=0;
    // std::sort_heap(nums.begin(),nums.end());
    int nn=nums.size();
    // while(!nums.empty())
    for(int i=0;i<nn-1;++i)
    {
        int cur=nums.front();
        s1=s1*10+cur;
        nums.erase(nums.begin()+i);
        if(!nums.empty())
        {
            cur=nums.front();
            s2=s2*10+cur;
            nums.erase(nums.begin()+i+1);
        }
    }
    return s1+s2;
}

int main()
{
    cout<<foo(1234);
}
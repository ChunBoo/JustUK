//given the value,return the count of a,b,c which a*a+b*b==c*c and all of a,b,c are in the range of [1,value]

#include<vector>
#include<iostream>
#include<cmath>
std::vector<std::vector<int>> pythagoreanTriplets(int val)  //can not work this version
{
    std::vector<std::vector<int>> ans{};
    std::vector<bool> attr(false,val*val+1);
    for(int i=0;i<=val;++i)
    {
        attr[i*i]=true;
    }
    for(int a=1;a<=val;++a)
    {
        for(int b=1;b<a;++b)
        {
            int tmp=a*a+b*b;
            if(attr[tmp]&&(tmp<=val*val))
            {
                ans.push_back(std::vector<int>{a,b,int(std::sqrt(tmp))});
            }
        }
    }
    return ans;
}
/*
std::vector<std::vector<int>> pythagoreanTriplets(int val)  //review codes
{
    std::vector<std::vector<int>> ans{};
    // int a=b=c=1;
    if(val<1)
        return ans;
    for(int a=1;a<=val;++a)
    {
        for(int b=1;b<a;++b)
        {
            int tmp=a*a+b*b;
            int c=static_cast<int>(std::sqrt(tmp));
            if((c<=val)&&(c*c==tmp))
            {
                ans.push_back(std::vector<int>{a,b,c});
                ans.push_back(std::vector<int>{b,a,c});
            }
        }
    }
    return ans;
}




















/*
std::vector<std::vector<int>> pythagoreanTriplets(int val)
{
    std::vector<std::vector<int>> ans{};
    for(int a=1;a<=val;++a)
    {
        for(int b=1;b<a;++b)
        {
            int c=int(std::sqrt(a*a+b*b));
            if((c*c==a*a+b*b)&&c<=val)
            {
                std::vector<int> tmp{a,b,c};
                ans.push_back(tmp);
            }
        }
    }
    return ans;
}
*/


int main()
{
    std::vector<std::vector<int>> ret=pythagoreanTriplets(10);
    if(ret.empty())
        std::cout<<"result is empty.\n";
    if(!ret.empty())
    {
        for(auto i:ret)
        {
            for(auto v:i)
            {
                std::cout<<v<<',';
            }
            std::cout<<'\n';
        }
    }
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using std::cout;
using VEC=std::vector<int>;

int fillCups(VEC& amount)
{
    int ans=0;
    std::vector<int>::iterator maxVal=std::max_element(amount.begin(),amount.end());
    while(*maxVal>0)
    {
        std::sort(amount.begin(),amount.end(),std::greater<int>());
        amount[0]-=1;
        amount[1]-=1;
        maxVal=std::max_element(amount.begin(),amount.end());
        ans+=1;
    }
    return ans;
}

int main()
{
    VEC amount{3,4,5};
    cout<<fillCups(amount);
}
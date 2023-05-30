#include<iostream>
#include<vector>
#include<cmath>

using std::cout;
using VEC=std::vector<int>;

VEC foo(const VEC& prices,int fee,int i)
{

    if(i<0)
    {
        return VEC{0,INT_MIN};
    }
    VEC tmp=foo(prices,fee,i-1);  //tmp[0]--maxProfit, tmp[1]---current balance
    VEC res{};
    res.push_back(std::max(tmp[0],prices[i]+tmp[1]-fee));
    res.push_back(std::max(tmp[1],tmp[0]-prices[i]));
    return res;
}

int maxProfit(const VEC& prices,int fee)
{
    VEC ans=foo(prices,fee,prices.size()-1);
    return ans[0];
}

int main()
{
    VEC prices{{6, 1, 7, 2, 8, 4}};
    int fee=2;
    cout<<maxProfit(prices,fee);
}
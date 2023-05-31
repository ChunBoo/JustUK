#include<iostream>
#include<vector>
#include<cmath>

using VEC=std::vector<int>;
using std::cout;



VEC foo(const VEC& prices,int i)
{
    VEC ans{INT_MIN,INT_MIN,0};
    if(i<0)
        return ans;
    
    VEC tmp=foo(prices,i-1); //tmp0--sold, tmp1--hold, tmp2--cooldown
    ans[0]=tmp[1]+prices[i];
    ans[1]=std::max(tmp[1],tmp[2]-prices[i]);
    ans[2]=std::max(tmp[2],tmp[0]);
    return ans;
}

int main()
{
    VEC prices{1,2,3,0,2};
    VEC ans=foo(prices,prices.size()-1);
    int ret=ans[0];
}
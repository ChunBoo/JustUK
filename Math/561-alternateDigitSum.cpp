#include<iostream>
#include<string>
#include<vector>
using std::cout;
using STR=std::string;
using VEC=std::vector<int>;


int alternateSum(int n)
{
    STR s=std::to_string(n);
    int ans=0,sign=1;
    for(auto &c:s)
    {
        ans+=(sign*(c-'0'));
        sign*=-1;
    }
    return ans;
} 

int alternateSum2(int n)  //need to understand this method
{
    VEC v{};
    int ans=0,sign=1;
    while(n)
    {
        ans+=(n%10)*(-sign);
        sign=-sign;
        n/=10;
    }

    return ans*sign;
} 


int main()
{
    cout<<alternateSum(123);
    cout<<alternateSum2(123);
}

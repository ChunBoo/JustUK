#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using std::cout;
using STR=std::string;
using VEC=std::vector<int>;


VEC separateDigits(int n)
{
    STR s=std::to_string(n);
    VEC ans{};
    for(auto c:s)
    {
        ans.push_back(c-'0');
    }
    return ans;
}
VEC separateDigits2(int n)
{

    VEC ans{};
    while (n)
    {
       ans.push_back(n%10);
       n/=10;
    }
    std::reverse(ans.begin(),ans.end());
    return ans;   
}


int main()
{
    VEC res=separateDigits2(19810303);
    // VEC res=separateDigits2();
    for(auto i:res)
        cout<<i<<',';
}
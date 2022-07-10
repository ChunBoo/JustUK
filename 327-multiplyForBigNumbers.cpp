#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using DT=std::string;

void bigNumbersMultiply(DT& sa, DT& sb, DT& res)
{
    int lenA=sa.size(),lenB=sb.size();
    std::vector<int> ans(lenA+lenB,0);
    std::reverse(sa.begin(),sa.end());
    std::reverse(sb.begin(),sb.end());

    for(int i=0;i<lenA;++i)
    {
        for(int j=0;j<lenB;++j)
        {
            ans[i+j]+=(sa[i]-'0')*(sb[j]-'0');
            ans[i+j+1]+=ans[i+j]/10;
            ans[i+j]%=10;
        }
    }
    int idx=0;
    std::reverse(ans.begin(),ans.end());
    while(idx<ans.size()&&ans[idx]==0) ++idx;
    if(idx==ans.size()-1)
        res="0";
    for(;idx<ans.size();++idx)
    {
        res+=std::to_string(ans[idx]);
    }
}


int main()
{
    DT a{"123"},b{"456"};
    DT res{};
    bigNumbersMultiply(a,b,res);
    std::cout<<res;
}
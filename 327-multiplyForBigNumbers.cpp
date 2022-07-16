//given two big numbers as string format,calculate the multiply 

#include<string>
#include<vector>
#include<iostream>
#include<algorithm>  //for std::reverse
using DT=std::string;

void bigNumbersMultiply(DT& sa, DT& sb, DT& res)  //can not be const DT&, as we will reverse the source strings
{
    int lenA=sa.size(),lenB=sb.size();
    if(!lenA || !lenB)
        return ;

    std::vector<int> tmp(lenA+lenB,0);
    std::reverse(sa.begin(),sa.end());
    std::reverse(sb.begin(),sb.end());
    for(int i=0;i<lenA;++i)
    {
        for(int j=0;j<lenB;++j)
        {
            tmp[i+j]+=((sa[i]-'0')*(sb[j]-'0'));
            tmp[i+j+1]+=tmp[i+j]/10;
            tmp[i+j]%=10;
        }
    }
    std::reverse(tmp.begin(),tmp.end());
    int idx=0;
    while((idx<tmp.size())&&(!tmp[idx])) ++idx;
    if(idx==tmp.size())  //here should be tmp.size()
        res="0";   
    for(;idx<tmp.size();++idx)
    {
        res+=std::to_string(tmp[idx]);
    }
}


int main()
{
    DT a{"123"},b{"0"};
    DT res{};
    bigNumbersMultiply(a,b,res);
    std::cout<<res;
}
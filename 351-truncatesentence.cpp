#include<string>
#include<vector>
#include<iostream>

using VEC=std::vector<std::string>;
using STR=std::string;

STR truncateString(const STR& s,int k)
{
    STR ans{};
    if(k<=0)
        return ans;

    VEC tmp{};
    size_t prePos=0, curPos=s.find(',');
    while(curPos!=std::string::npos)
    {

        tmp.push_back(s.substr(prePos,curPos-prePos));
        prePos=curPos;
        curPos=s.find(',',curPos+1);
    }
    tmp.push_back(s.substr(prePos));
    for(int i=0;i<k;++i)
    {
        ans+=tmp[i];
    }
    return ans;
}

int main()
{
    STR s="Hello,A,Hi,B";
    std::cout<<truncateString(s,3);
    return 0;
}
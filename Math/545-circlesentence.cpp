#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using STR=std::string;
using VEC=std::vector<STR>;
using std::cout;

bool isCircleSentence2(const STR& s)
{
    VEC tmp{};
    char delimiter{' '};
    auto pos=s.find(delimiter);
    int prePos=-1;
    while(pos!=std::string::npos)
    {
        STR ss{s.substr(prePos+1,pos-1)};
        tmp.push_back(ss);
        prePos=pos;
        pos=s.find(delimiter,pos+1);
    }
    return false;
}
bool isCircleSentence(const STR& s)
{
    VEC tmp{};
    char delimiter{' '};
    auto iss=std::istringstream{s};
    STR str{};
    while(iss>>str)
        tmp.push_back(str);

    int n=tmp.size();
    for(int i=0;i<n;++i)
    {
        int tmpSize=tmp[i].size();
        if(tmp[i][tmpSize-1]!=tmp[(i+1)%n][0])
            return false;
    }
    return true;
}

int main()
{
    STR s{"a apple eat todaya"};
    cout<<isCircleSentence2(s);
}
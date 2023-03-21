#include<iostream>
#include<string>
#include<vector>

using std::cout;
using STR=std::string;
using VEC=std::vector<STR>;


STR convert(const STR& s,int numRows)
{
    VEC tmp(numRows,"");
    int i=0,flag=-1;

    for(auto &c:s)
    {
        tmp[i]+=c;
        if(i==0 ||i==numRows-1)
            flag*=-1;
        i+=flag;
    }
    STR ans{};
    for(auto &_s:tmp)
    {
        ans+=_s;
    }
    return ans;
}

int main()
{
    STR s = "PAYPALISHIRING";
    int numRows = 3;
    cout<<convert(s,numRows);
}
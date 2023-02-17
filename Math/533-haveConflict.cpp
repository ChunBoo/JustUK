#include<string>
#include<iostream>
#include<vector>
using std::cout;
using STR=std::string;
using VEC=std::vector<STR>;
bool hasConflict(const VEC& t1, const VEC& t2)
{
    STR a1=t1[0],a2=t1[1];
    STR b1=t2[0],b2=t2[1];
    return std::max(a1,b1)<=std::min(a2,b2);
}

int main()
{
VEC time1{"02:00","04:00"};
VEC time2{"03:10","05:00"};
cout<<hasConflict(time1,time2);
}
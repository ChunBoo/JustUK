#include<iostream>
#include<vector>
#include<string>

using STR=std::string;
using std::cout;
using VEC=std::vector<int>;


int splitNum(int n)
{
    STR s{std::to_string(n)};
    // int nn=s.size();
    VEC bits(10,0);
    for(auto &c:s)
        bits[c-'0']+=1;
    int s1=0,s2=0,i=0;
    while(i<10)
    {
        while(i<10 && bits[i]==0) i+=1;
        if(i==10)
            break;
        s1=s1*10+i;
        bits[i]-=1;
        while(i<10&&bits[i]==0) i+=1;
        if(i==10) break;
        s2=s2*10+i;
        bits[i]-=1;
    }
    return s1+s2;
}

int main()
{
    cout<<splitNum(1234);
}
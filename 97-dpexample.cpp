//DP example
#include<iostream>
#include<map>

int fooTD(int index,std::map<int,int>& dic)
{
    if(index<=1)
        return 1;
    if(dic.find(index)!=dic.end())
        return dic[index];
    
    int value=fooTD(index-1,dic)+fooTD(index-2,dic);

    dic[index]=value;

    return value;
}

int fooDT(int index)
{
    int f0=0,f1=1;
    for(int i=0;i<index;++i)
    {
        int t=f0;
        f0=f1;
        f1=t+f1;
    }
    return f1;
}

int main()
{
    std::map<int,int> d{};
    int res=fooDT(3); //1,1,2,3,5,8
    std::cout<<"Result is: "<<res<<'\n';
    return 0;
}

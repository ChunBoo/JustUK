#include<string>
// #include<vector>
#include<map>
#include<iostream>
// #include <locale>         // std::locale, std::isdigit

using DT=std::string;
// using 
DT runLength(const DT& s)
{
    DT ans{};
    if(s.empty())
        return ans;
    // std::locale loc;
    int c=0;
    std::map<char,int> data{};

    for(char i:s)
    {
        // if(i>='0'&&i<='9')
        if(std::isdigit(i))
            c=c*10+i-'0';
        else
        {
            data[i]=c;
            c=0;
        }
    }

    std::map<char,int>::iterator iter=data.begin();
    for(;iter!=data.end();++iter)
    {
        DT tmp(iter->second,iter->first);  //std::string(number,character)
        ans+=tmp;
    }
    return ans;    
}


int main()
{
    // std::cout<<'1'-'0';
   DT s{"12a3b4c5d6e"};
   std::cout<<runLength(s);
   return 0;
}
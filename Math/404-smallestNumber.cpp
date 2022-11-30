#include<string>
#include<iostream>
#include<algorithm>
using STR=std::string;


int smallest(int n)
{
   if(n==0)
    return 0;

   if(n<0)
   {
    STR s=std::to_string(n);
    std::sort(s.begin(),s.end(),std::greater<char>());  //sorted with decreasing 
    return (-1)*std::stoi(s);
   } 
   else
   {
    STR s=std::to_string(n);
    std::sort(s.begin(),s.end());
    //get the index of first number is not zero
    int sp=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]!='0')
        {
            sp=i;
            break;
        }
    }
    return std::stoi(s[sp]+STR(s.begin(),s.begin()+sp)+STR(s.begin()+sp+1,s.end()));
   }
}

int main()
{
    int n=-319;
    std::cout<<smallest(n);
}
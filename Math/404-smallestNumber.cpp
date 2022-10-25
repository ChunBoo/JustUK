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
        std::sort(s.begin(),s.end(),std::greater<char>());
        return (-1)*std::stoi(s);
    }
    else
    {
        STR s=std::to_string(n);
        std::sort(s.begin(),s.end());
        //find the first element of not zero
        size_t sp=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]!='0')
            {
                sp=i;
                break;
            }
        }
        STR temp=s[sp]+STR(s.begin(),s.begin()+sp)+STR(s.begin()+sp+1,s.end());
        return std::stoi(temp);

    }
}

int main()
{
    int n=309;
    std::cout<<smallest(n);
}
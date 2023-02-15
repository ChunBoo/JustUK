#include<iostream>
#include<string>

using std::cout;
using STR=std::string;


int countTime(const STR& t)
{
    //t is "HH:MM"
    int ans=1;
    if(t[4]=='?')
        ans*=10;
    if(t[3]=='?')
        ans*=6;
    if((t[0]=='?')&&(t[1]=='?'))
        ans*=24;
    else
    {
        if(t[0]=='?')   //t[1] is not '?'
        {
            if(t[1]<'4')
                ans*=3;
            else
                ans*=2;
        }
        else  //t[0] is not '?'
        {
            if(t[0]<'2')
                ans*=10;
            else
                ans*=4;
        }
    }
    return ans;
}

int main()
{
    STR t{"?3:00"};
    cout<<countTime(t);
}
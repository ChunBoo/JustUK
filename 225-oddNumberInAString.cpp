//given a string which just contains integers, return the maximum odd number
#include<string>
#include<iostream>

std::string largestOddNumber(const std::string& s)
{
    if(s.empty())
        return "";
    
    int lastPos=0,sz=s.size();
    for(int i=sz-1;i>=0;--i)
    {
        if((s[i]-'0')&1)  //odd number
        {
            lastPos=i;
            break;
        }        
    }
    return s.substr(0,lastPos+1);
   
}

int main()
{
    std::string s{"1234568"};//should return 12345
    std::cout<<largestOddNumber(s);
    return 0;
}
//given a string,likes "1ArBBCa33DcEF4e90GcBBaDDrEEA", to return the lowercase chars are palindromic string or not

#include<string>
#include<iostream>
#include<ctype.h>
bool isPalindromicStringOfLowercase(const std::string& str)
{
    if(str.empty())
        return true;

    int sz=str.size();

    int start=0,end=sz-1;
    while(start<end)
    {
        while(!islower(str[start]))
            start+=1;
        while(!islower(str[end]))
            end-=1;
        if(str[start]!=str[end])
            return false;
        start+=1;
        end-=1;
    }
    return true;
}

int main()
{
    std::string str{"1ArBBCa33DcEF4e90GcBBaDDrEEA"};
    bool res=isPalindromicStringOfLowercase(str);
    std::cout<<res<<'\n';
    return 0;
}
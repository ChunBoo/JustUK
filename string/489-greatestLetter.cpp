#include<string>
#include<iostream>
#include<algorithm>

using STR=std::string;

char getGreatestLetter( STR s)
{
    // STR tmp=std::sort(s.begin(),s.end());
    std::sort(s.begin(),s.end());
    int n=s.size();
    for(int i=n-1;i>-1;--i)
    {
        char upper=std::toupper(s[i]);
        char lower=std::tolower(s[i]);
        
        if(s.find(upper)!=std::string::npos && s.find(lower)!=std::string::npos)
            return upper;
    }
    return ' ';  //can not return '' which is empty character
}

int main()
{
    STR s{"AbCdEkfGhIjBK"};
    std::cout<<getGreatestLetter(s);
}
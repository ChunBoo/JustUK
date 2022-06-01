#include<string>
#include<iostream>


void deleteDuplicated(std::string& str)
{
    std::string base=str;
    while(str.find("XX")!=std::string::npos)
        str=str.replace(str.find("XX"),2,"X");
    while(str.find("YY")!=std::string::npos)
        str=str.replace(str.find("YY"),2,"Y");
}

int main()
{
    std::string s{"YYYYXYXX"};
    deleteDuplicated(s);
    std::cout<<s<<'\n';
    return 0;
}
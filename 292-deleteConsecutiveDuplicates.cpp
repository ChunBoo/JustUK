//given a string, 
// This constant is defined with a value of -1, which because size_t is an unsigned integral type, 
// it is the largest possible representable value for this type.
#include<string>
#include<iostream>

void deleteDuplicated(std::string& str)
{
    while(str.find("XX")!=std::string::npos)
        str.replace(str.find("XX"),2,"X");
    while(str.find("YY")!=std::string::npos)
        str.replace(str.find("YY"),2,"Y");
}

int main()
{
    std::string s{"YYYYXYXX"};
    deleteDuplicated(s);
    std::cout<<s<<'\n';
    return 0;
}
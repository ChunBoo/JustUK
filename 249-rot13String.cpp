//convert a string to anthoer one with the rule of 

#include<iostream>
#include<string>

std::string rot13(std::string& s)
{
    std::string ans{};
    if(s.empty())
        return ans;
    for(auto c:s)
    {
        if(std::isupper(c))
            ans+='A'+(c-'A'+13)%26;
        else if (std::islower(c))
        {
            ans+='a'+(c-'a'+13)%26;
        }
        else
            ans+=c;
    }
    return ans;
}

int main()
{
    std::string s{"Hello"};
    std::cout<<rot13(s);
    return 0;
}
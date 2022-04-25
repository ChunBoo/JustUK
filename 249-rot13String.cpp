#include<iostream>
#include<string>

std::string rot13(std::string& s)
{
    std::string ans;
    for(auto i:s)
    {
        if(std::isupper(i))
        {
            ans+='A'+(i-'A'+13)%26;
        }
        else if(std::islower(i))
        {
            ans+='a'+(i-'a'+13)%26;
        }
        else
            ans+=i;
    }
    return ans;
}

int main()
{
    std::string s{"HELLO"};
    std::cout<<rot13(s);
    return 0;
}
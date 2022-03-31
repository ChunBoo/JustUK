//given a string,return the first unique char

#include<string>
#include<iostream>
#include<map>
int findoutTheFirstUniqueChar(const std::string& s)
{
    if(s.empty())
        return -1;
    std::map<char,int> c;
    for(auto i:s)
    {
        c[i]+=1;
    }
    for(int i=0;i<s.size();++i)
    {
        if(c[s[i]]==1)
            return i;
    }
    return -1;
}


int main()
{
    std::string s{"abbacdeff"};
    std::cout<<findoutTheFirstUniqueChar(s);
    return 0;
}
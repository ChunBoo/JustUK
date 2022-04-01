//given a string,return the first unique char

#include<string>
#include<iostream>
#include<map>
#include<vector>

int findoutTheFirstUniqueCharVector(const std::string& s)
{
    std::vector<int> v(26,0);
    for(auto i:s)
    {
        v[i-97]+=1;
    }
    for(int i=0;i<s.size();++i)
    {
        if(v[s[i]-97]==1)
            return i;
    }
    return -1;
}

int findoutTheFirstUniqueChar(const std::string& s)
{
    if(s.size()==0)
        return -1;
    std::map<char,int> m{};
    for(auto i:s)
        m[i]+=1;
    for(int i=0;i<s.size();++i)
    {
        if(m[s[i]]==1)
            return i;
    }
    return -1;
}


int main()
{
    std::string s{"abbacdeff"};
    int pos=findoutTheFirstUniqueCharVector(s);
    std::cout<<pos<<","<<s[pos];
    return 0;
}
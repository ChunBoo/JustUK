#include<string>
#include<iostream>
#include<vector>
#include<map>
bool check(std::vector<std::string>& strs)
{
    int sz=strs.size();
    if(sz==0)
        return true;
    
    std::map<char,int> count;
    for(auto s:strs)
    {
        for(auto c:s)
        {
            count[c]+=1;
        }
    }
    for(auto i:count)
    {
        if(i.second%sz!=0)
            return false;
    }
    return true;
}

int main()
{
    std::vector<std::string> s{"adc","dcd","aacd"};
    std::cout<<check(s);
    return 0;
}
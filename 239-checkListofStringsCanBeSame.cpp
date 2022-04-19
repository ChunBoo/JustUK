//given a list of strings,return true if we can rearrange each string to make them same 

#include<string>
#include<iostream>
#include<vector>
#include<map>
bool check(std::vector<std::string>& strs)
{
    if(strs.empty())
        return true;
    //iterate each sub string
    int sz=strs.size();
    std::map<char,int> m{};
    for(auto s:strs)
    {
        for(auto c:s)
            m[c]+=1;
    }
    for(auto i:m)
    {
        if(i.second%sz!=0)
            return false;
    }
    return true;
    
}

int main()
{
    std::vector<std::string> s{"adc","dc","aacd"};
    std::cout<<check(s);
    return 0;
}
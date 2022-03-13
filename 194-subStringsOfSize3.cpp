#include<string>
#include<vector>
#include<iostream>
#include<set>
using DT=std::vector<std::string>;

int getCountOfSubStringWithSizeOf3(const std::string& str)
{
    int sz=str.size(),i=0,ans=0;
    if(sz<3)
        return 0;
    
    while(i<sz-2)
    {
        std::set<char> s{};
        std::string tmpString=str.substr(i,3);
        for(auto c:tmpString)
            s.insert(c);
        if(s.size()==3)
            ans+=1;
        i+=1;
    }
    return ans;
}

DT getSubStringsOfSize3(const std::string& str)
{
    DT ans{};
    if(str.size()<3)
        return ans;

    int sz=str.size(),i=0;
    while(i<sz-2)
    {
        std::string tmpString=str.substr(i,3);
        ans.push_back(tmpString);
        i+=1;
    }
    return ans;
}

int main()
{
    int res=getCountOfSubStringWithSizeOf3("abcdd");
    // DT res=getSubStringsOfSize3("abcde");
    // for(auto s:res)
        // std::cout<<s<<'\n';
    std::cout<<res<<'\n';
    return 0;
}
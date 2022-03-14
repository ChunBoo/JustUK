#include<iostream>
#include<string>
#include<vector>

using DT=std::vector<std::string>;
DT getSubStringsOfSize3(const std::string& str)
{
    DT ans;
    if(str.size()<3)
        return ans;

    size_t len=str.size();
    int i=0;
    for(;i<len-2;++i)
    {
        if(str[i]!=str[i+1]&&str[i]!=str[i+2]&&str[i+2]!=str[i+1])
            ans.push_back(std::string(1,str[i])+str[i+1]+str[i+2]);
    }
    return ans;
}
DT getSubStringsOfSize31(const std::string& str)
{
    DT ans;
    if(str.size()<3)
        return ans;
    
    size_t len=str.size();
    int i=0;
    while(i<len-2)
    {
        ans.push_back(str.substr(i,3));
        i+=1;
    }
    return ans;
}

int main()
{
    std::string str="abccdef";
    DT res=getSubStringsOfSize3(str);
    for(auto w:res)
    {
        // std::cout<<'\n';
        for(auto c:w)
            std::cout<<c<<",";
        std::cout<<'\n';
    }
    return 0;
}
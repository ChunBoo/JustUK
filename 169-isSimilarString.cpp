//given a vector of strings, each string has same length,but just has one different char，likes "abcd", "abce"
//return true,if there are two strings are similar
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using DT=std::vector<std::string>;

bool isSimilarStrings(DT str)
{
    if(str.empty())
        return false;
    
    int sz=str.size();
    DT tempVector{};
    for(int i=0;i<sz;++i)
    {
        for(int pos=0;pos<str[i].size();++pos)
        {    
            std::string curString=str[i];  //needs this temp variable to save current string,as the replace function will change original string
            std::string tempString=curString.replace(pos,1,1,'?');
            if(std::find(tempVector.begin(),tempVector.end(),tempString)!=tempVector.end())
                return true;
            tempVector.push_back(tempString);
        }
    }
    return false;
}


int main()
{
    DT strings{"abcd","abce","acde","efgh"};
    bool res=isSimilarStrings(strings);
    std::cout<<res<<'\n';
    return 0;
}
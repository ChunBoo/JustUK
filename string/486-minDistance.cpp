#include<string>
#include<iostream>
#include<vector>
#include<cmath>
#include<sstream>
using STR=std::string;
using VEC=std::vector<STR>;

int minDistance( STR& s,const STR& w1, const STR& w2)
{
    //split the words by space
    VEC strings{};
    STR tmpString{};
    std::stringstream ss(s);
    while(std::getline(ss,tmpString,' '))
    {
        strings.push_back(tmpString);
    }

    int sz=strings.size();

    int ans=INT_MAX;
    int last=-1;
    
    for(int i=0;i<sz;++i)
    {
        if((strings[i]==w1) ||(strings[i]==w2))
        {
            if((last!=-1)&&(strings[last]!=strings[i]))
            {
                ans=std::min(ans,i-last-1);
            }
            last=i;
        }
    }
    return ans;
}

int main()
{
    STR s{"a b b b c c d"};
    std::cout<<minDistance(s,"a","c");
}

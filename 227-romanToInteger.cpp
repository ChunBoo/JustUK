#include<string>
#include<map>
#include<iostream>

int romanToInteger(const std::string& s)
{
    if(s.empty())
        return 0;
    int ans=0;
    std::map<char,int> data;
    data['I']=1;
    data['V']=5;
    data['X']=10;
    data['L']=50;
    data['C']=100;
    data['D']=500;
    data['M']=1000;
    for(int i=0;i<s.size()-1;++i)
    {
        if(data[s[i]]<data[s[i+1]])
            ans-=data[s[i]];
        else
            ans+=data[s[i]];
    }
    ans+=data[s[s.size()-1]];
    return ans;
}

int main()
{
    std::string s="XL";
    std::cout<<romanToInteger(s);
    return 0;
}
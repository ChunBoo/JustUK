#include<string>
#include<map>
#include<iostream>
/*
罗马数字一共有7个基本符号，分别为：
I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000），括号内的值表示其大小。
*/
int romanToInteger(const std::string& s)
{
    if(s.empty())
        return 0;
    int ans=0;
    int len=s.size();
    std::map<char,int> data{};
    data['I']=1;
    data['V']=5;
    data['X']=10;
    data['L']=50;
    data['C']=100;
    data['D']=500;
    data['M']=1000;
    for(int i=0;i<len-1;++i)
    {
        if(data[s[i]]<data[s[i+1]])
            ans-=data[s[i]];
        else
            ans+=data[s[i]];
    }
    ans+=data[s[len-1]]; //最后一位应该是正数，因为它没有下一个元素可以比较,所以再加上最后一位元素的值即可。
    return ans;
}

int main()
{
    std::string s="XL";
    std::cout<<romanToInteger(s);
    return 0;
}
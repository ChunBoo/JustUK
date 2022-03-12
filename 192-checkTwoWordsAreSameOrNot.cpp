//given two words,return their sum is same with the third one

#include<string>
#include<iostream>
#include<map>
int foo12(const std::string& s)
{
    int ans=0;
    for(auto i:s)
    {
        ans=ans*10+(i-'a');
    }
    return ans;
}


int foo1(const std::string& s)//map
{
    std::map<char,char> m;
    int ans=0;
    for(int i='a';i<='z';++i)
    {
        m[i]=i-'a';
    }
    for(auto i:s)
    {
        ans=ans*10+m[i];
    }
    return ans;
}

int main()
{
    std::string s1="acb",s2="cba",s3="cdb";

    std::cout<<((foo1(s1)+foo1(s2))==foo1(s3))<<'\n';
    return 0;
}
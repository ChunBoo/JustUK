#include<string>
#include<iostream>

using STR=std::string;

STR removeDigit(const STR& s,char digit)
{
    STR ans{"0"};
    int n=s.size();
    for(int i=0;i<n;++i)
    {
        if(s[i]==digit)
        {
            STR temp=s.substr(0,i)+s.substr(i+1,n-i-1);
            ans=std::to_string(std::max(std::stoi(ans),std::stoi(temp)));
        }
    }
    return ans;
}
int main()
{
    STR s{"11"};
    std::cout<<removeDigit(s,'1');
}
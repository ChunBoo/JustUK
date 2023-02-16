#include<iostream>
#include<string>
#include<vector>
#include<map>

using std::cout;
using STR=std::string;
using VEC=std::vector<char>;
using MAP=std::map<char,VEC>;  //'1':2

STR groupBy(const STR& s)
{
   STR ans{};
   int n=s.size();
   for(int i=0;i<n;)
   {
    int j=i+1;
    while(s[i]==s[j])
        j+=1;
    int cnt=j-i;
    ans+=('0'+cnt);
    ans+=s[i];
    i=j;
   }
   return ans;
}

STR f(int n)
{
    if(n==1)
        return "1";
    STR a=f(n-1);
    STR ans=groupBy(a);
    return ans;
}

STR countAndSay(int n)
{
    return f(n);
}

int main()
{
    cout<<countAndSay(5);
}
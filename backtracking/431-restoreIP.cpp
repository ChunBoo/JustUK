/*
valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, “0.1.2.201” and “192.168.1.1” are valid IP addresses, but “0.011.255.245”, “192.168.1.312” and “192.168@1.1” are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

Example 1:
Input: s = “25525511135”
Output: [“255.255.11.135″,”255.255.111.35”]

Example 2:
Input: s = “0000”
Output: [“0.0.0.0”]

Example 3:
Input: s = “101023”
Output: [“1.0.10.23″,”1.0.102.3″,”10.1.0.23″,”10.10.2.3″,”101.0.2.3”]

Constraints:
1 <= s.length <= 20
s consists of digits only.
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using STR=std::string;
using VEC=std::vector<STR>;
/*
template <typename Iter>
std::string join(Iter begin, Iter end, std::string const& separator)
{
  std::ostringstream result;
  if (begin != end)
    result << *begin++;
  while (begin != end)
    result << separator << *begin++;
  return result.str();
}
*/
STR join(const VEC& ss, const STR& separator)
{
    STR ans{};
    for(auto &s:ss)
    {
        ans+=(s+separator);
    }
    return ans;
}


void f(VEC& cur, VEC& ans,STR& s)
{
    int _sum=0;
    for(auto &v:cur)
        _sum+=v.size();
    
    if(cur.size()==4)
    {
        if(_sum==s.size())
            ans.push_back(join(cur,"."));
        return;
    }
    for(int i=_sum;i<std::min(_sum+3,(int)s.size());++i)
    {
        STR x=s.substr(_sum,i-_sum+1);
        
        int tmp=std::stoi(x);
        if( (tmp>=0 && tmp<=255 ) &&(x=="0" || (x.size()>0 && x[0]!='0')))
        {
            cur.push_back(x);
            f(cur,ans,s);
            cur.pop_back();
        }
    }
}

VEC restoreAddress(STR& s)
{
    VEC ans{};
    VEC cur{};
    int sz=s.size();
    if(sz<4 || sz>12)
        return ans;
    
    f(cur,ans,s);
    return ans;
}

int main()
{
    STR s{"12345"};
    VEC res=restoreAddress(s);
    for(auto &v:res)
    {
        std::cout<<v<<',';
    }
}
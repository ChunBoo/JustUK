
/*

given a lowercase alphabet string s. 
Return the number of ways to split the string into two strings such that the number of distinct characters in each string is the same.

Constraints
1 ≤ n ≤ 100,000 where n is the length of s
Example 1
Input
s = “abaab”
Output
2
Explanation
We can split it by “ab” + “aab” and “aba” + “ab”

for each index i split (0, i) and (i + 1, n – 1)
add +1 if both split contain equal distinct character.
try checking from left and based on that check from right
*/
#include<string>
#include<iostream>
#include<map>
using STR=std::string;
using MAP=std::map<char,int>;

MAP myCounter(STR s)
{
    MAP ans{};
    for(auto &c:s)
    {
        ans[c]+=1;
    }
    return ans;
}
int split2(STR& s)
{
    if(s.empty())
        return 0;
    MAP c1=myCounter(STR(""));
    MAP c2=myCounter(s);
    int ans=0;
    for(int i=0;i<s.size();++i)
    {
        // STR s1=s.substr(0,i);
        // STR s2=s.substr(i);
        c1[s[i]]+=1;
        c2[s[i]]-=1;
        if(c2[s[i]]==0)
            c2.erase(s[i]);
        if(c1.size()==c2.size())
            ans+=1;

    }
    return ans;
}

int main()
{
    STR s{"abaab"};
    std::cout<<split2(s);
}
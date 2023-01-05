#include<string>
#include<set>
#include<iostream>

using SET=std::set<char>;
using STR=std::string;


int lengthOfLongestSubstring(const STR& s)
{
    int sz=s.size();
    int r=0;
    SET win{};
    int ans{};
    while(r<sz)
    {
        while(win.find(s[r])!=win.end())
        {
            auto it=win.begin();
            win.erase(it);
        }
        win.insert(s[r]);
        ans=std::max(ans,int(win.size()));
        r+=1;
    }
    return ans;
}

int main()
{
    STR s{"abcdebbc"};
    std::cout<<lengthOfLongestSubstring(s);
}
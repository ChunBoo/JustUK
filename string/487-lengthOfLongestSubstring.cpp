#include<iostream>
#include<map>
#include<string>
#include<set>

using STR=std::string;
using SET=std::set<char>;
using MAP=std::map<char,int>;

int longestSubString(const STR& s )
{
    int n=s.size();
    MAP d{};
    int r=0,ans=0,l=0;
    SET st{};
    while(r<n)
    {
        char x=s[r];
        int idx=d[x];
        while(l<idx)
        {
            st.erase(s[l]);
            l+=1;
        }
        st.insert(x);
        ans=std::max(ans,static_cast<int>(st.size()));
        d[x]=r;
        r+=1;
    }
    return ans;
}
int main()
{
    STR s{"abcdebbc"};
    std::cout<<longestSubString(s);
}
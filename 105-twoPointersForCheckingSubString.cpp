//using double pointers for checking substring

#include<string>
#include<iostream>

using namespace std;

bool isSubString(const std::string& s, const std::string& t)
{
    if(s.empty())
        return true;
    
    int ls=s.size(),lt=t.size();
    if(ls>lt)
        return false;
    
    int si=0,st=0;
    while(si<ls&&st<lt)
    {
        if(s[si]==t[st])
            si++;
        st++;
    }
    return si==ls;
}

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.size()==0&&s.size()>0)  //empty string is one substring 
            return false;

        int _s=0,_t=0;
        while(_s<s.size()&&_t<t.size()){
            if(s[_s]==t[_t]){
                ++_s;
            }
            ++_t;
        }
        return _s==s.size();
    }
};
int main()
{
    std::string s{""};
    std::string t{"acdbde"};

    bool res=isSubString(s,t);
    std::cout<<s<<" is a substring of "<<t<<" ? "<<(res?"Yes":"No")<<'\n';

    return 0;
}
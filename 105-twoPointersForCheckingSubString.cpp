//using double pointers for checking substring

#include<string>
#include<iostream>

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


int main()
{
    std::string s{""};
    std::string t{"acdbde"};

    bool res=isSubString(s,t);
    std::cout<<s<<" is a substring of "<<t<<" ? "<<(res?"Yes":"No")<<'\n';

    return 0;
}
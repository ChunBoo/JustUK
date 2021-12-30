//using double pointers for checking substring

#include<string>
#include<iostream>


bool isSubString(const std::string& s, const std::string& t)
{
    int ls=s.size();
    int lt=t.size();

    if(!ls||!lt||ls>lt)
        return false;
    
    int is=0,it=0;
    while(is<ls&&it<lt)
    {
        if(s[is]==t[it])
            is+=1;
        it+=1;
    }
    return is==ls;    
}

int main()
{
    std::string s{"abc"};
    std::string t{"acddce"};

    bool res=isSubString(s,t);
    std::cout<<s<<" is a substring of "<<t<<" ? "<<(res?"Yes":"No")<<'\n';

    return 0;
}
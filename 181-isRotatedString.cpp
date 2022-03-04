// "abc" and "bca" are rotated strings

#include<string>
#include<iostream>

bool isRotatedStrings(std::string& s1,std::string& s2)
{
    int l1=s1.size(),l2=s2.size();
    
    if(l1!=l2)
        return false;
    
    // for(int i=0;i<l1;++i)
    // {
    //     std::string tmpString;
    //     if(i<1)
    //         tmpString=s1.substr(i+1,l1-1)+s1[i];
    //     else
    //         tmpString=s1.substr(i,l1-1)+s1[i-1]+s1[i-2];
    //     if(tmpString==s2)
    //         return true;
    // }
    std::string tmpString=s1+s1;
    return tmpString.find(s2)!=tmpString.npos;
}

int main()
{
    std::string s1="abc",s2="cba";
    std::cout<<isRotatedStrings(s1,s2)<<'\n';
    return 0;
}
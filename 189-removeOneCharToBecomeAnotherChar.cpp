//two pointers method
//s0 has one more char than s1, check if can remove one char from s0 to become s1
#include<iostream>
#include<string>


bool check(const std::string& s0, const std::string& s1)
{
    size_t l0=s0.size(),l1=s1.size();
    if(l1+1!=l0)
        return false;
    
    int i=0, j=0;
    while(i<l0&&j<l1)
    {
        if(s1[j]==s0[i])
            j+=1;
        i+=1;
    }
    return j==l1;
}

int main()
{
    std::string s0="abcde",s1="abde";
    std::cout<<check(s0,s1);
    return 0;
}
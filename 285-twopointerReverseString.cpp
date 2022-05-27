#include<string>
#include<iostream>

using DT=std::string;

void reverseStringForEnglishLetters(DT& s)
{
    if(s.empty())
        return;
    
    int R=s.size()-1,L=0;
    while(L<R)
    {
        while(L<R && !std::isalpha(s[L]))
            L+=1;
        while(L<R && !std::isalpha(s[R]))
            R-=1;
        
        char t=s[L];
        s[L]=s[R];
        s[R]=t;

        L+=1;
        R-=1;    
    }
}

int main()
{
   DT s="a_b_cde";
   reverseStringForEnglishLetters(s);
   std::cout<<s;
   return 0;
}
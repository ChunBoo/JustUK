#include<string>
#include<iostream>

int longestValidParentheses(std::string& s)
{
    if(s.empty())
        return 0;
    
    int bal=0,ans=0;
    for(auto c:s)
    {
        if(c=='(')
            bal+=1;
        else
        {
            bal-=1;
            if(bal>=0)
                ans+=1;
            if(bal<0)
                bal=0;
        }
    }
    return ans*2;
}

int main()
{
    std::string s="))(())";
    std::cout<<longestValidParentheses(s);
    return 0;
}
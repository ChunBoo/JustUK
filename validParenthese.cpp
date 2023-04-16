#include<iostream>
#include<string>
#include<stack>
//valid parenthese check 

bool isValidParenthese(const std::string& s)  //just for only type of parenthese,such as ( )
{
    if(s.size()==1)
        return false;
    if(s.empty())
        return true;
    std::string openString="([{";
    std::string closedString=")]}";
    int balance=0;

    for(auto &i:s)
    {
        if(openString.find(i)!=std::string::npos)
            balance++;
        else
            balance--;
    }
    return balance==0;
}

bool isValidParentheseUsingStack(const std::string& s)
{
    std::stack<char> st;
    if(s.empty())
        return true;
    std::string openString="([{";
    std::string closedString=")]}";
    std::string completedParenthese{"()[]{}"};
    for(auto &i:s)
    {
        if(openString.find(i)!=std::string::npos)
            st.push(i);
        else
        {
            if(st.size()==0)
                return false;
            std::string tempStr;
            tempStr+=st.top();
            tempStr+=i;
            if(completedParenthese.find(tempStr)==std::string::npos)
                return false;
            else
                st.pop();
        }
    }
    return st.size()==0;
}

int main()
{
    std::string test{"(])"};
    bool isValid=isValidParentheseUsingStack(test);
    std::cout<<test<<" is valid parenthese? "<<(isValid?"True":"False")<<"\n";
    return 0;
}
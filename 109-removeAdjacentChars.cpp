//using stack to remove the adjacent chars from a string
#include<string>
#include<stack>
#include<iostream>
#include<vector>

std::string removeAdjacentCharsFromString(const std::string& s)
{
    
    int sz=s.length();
    if(sz==0||sz==1)
        return s;
    
    std::stack<char> st{};
    for(int i=0;i<sz;++i)
    {
        if(!st.empty()&&st.top()==s[i])
            st.pop();
        else    
            st.push(s[i]);
    }
    std::string ret(sz,' ');  //std::string initialized way
    // std::string ret{};  // this way can not work
    for(int i=st.size()-1;i>=0;--i)
    {
        ret[i]=st.top();
        st.pop();
    }
    return ret;
}


int main()
{
    std::string s{"abccbae"};
    std::string ret=removeAdjacentCharsFromString(s);
    std::cout<<"After removing: "<<ret<<"\n";
    return 0;
}
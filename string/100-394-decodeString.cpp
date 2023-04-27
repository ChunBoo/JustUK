#include<iostream>
#include<stack>
#include<string>

using STR=std::string;
using PAIR=std::pair<int,STR>;
using STACK=std::stack<PAIR>;
using std::cout;
STR decodeString(STR s)
{
    int num=0;
    STR ans{};
    STACK st{};
    for(auto &c:s)
    {
        if(c>='1'&&c<='9')
        {
            num=num*10+c-'0';
        }
        else if(c=='[')
        {
            PAIR tmp=std::make_pair(num,ans);
            st.push(tmp);
            num=0;
            ans="";
        }
        else if(c==']')
        {
            PAIR top=st.top();
            st.pop();
            int cnt=top.first;
            STR preString=top.second;
            STR tmp{};
            for(int i=0;i<cnt;++i)
                tmp+=ans;
            ans=preString+tmp;
        }
        else
            ans+=c;
    }
    return ans;
}

int main()
{
    STR s{"3[a]2[bc]"};
    cout<<decodeString(s);
}
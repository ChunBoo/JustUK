#include<vector>
#include<iostream>
#include<string>
using VEC=std::vector<int>;
using STR=std::string;


STR textEditor(const STR& s)
{
    STR ans{};
    int n=s.size();

    for(int i=0;i<n;++i)
    {
        if(i>0&&s[i]=='-'&&s[i-1]=='<')
        {
            ans.pop_back();
            if(ans.size()>0)
                ans.pop_back();   
        }
        else
            ans+=s[i];
    }
    return ans;
}

int main()
{
    STR s{"ab<-z"};
    std::cout<<textEditor(s);
}

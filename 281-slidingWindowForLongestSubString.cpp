#include<map>  //for the sliding windows
#include<string>  //for the string
#include<iostream>


int longestSubString(const std::string& str)
{
    if(str.empty())
        return 0;

    std::map<char,int> win{};// int is the sum of chars
    int ans=0,n=str.size(),L=0,R=0;
    while(R<n)
    {
        win[str[R]]+=1;
        while(L<=R&&(win.size()>3))
        {
            win[str[L]]-=1;
            if(win[str[L]]==0)
            {
                win.erase(str[L]);
                L+=1;
            }
        }
        ans=std::max(ans,R-L+1);
        R+=1;
    }
    return ans;
}


int main()
{
    std::string s{"abccbbb"};
    std::cout<<longestSubString(s);
    return 0;
}
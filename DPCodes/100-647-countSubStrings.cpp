#include<string>
#include<iostream>

using STR=std::string;
using std::cout;


class Solution {
public:
    int countSubstrings(STR s) {
        int num = 0;
        int n = s.size(); 
        for(int i=0;i<n;i++)//遍历回文中心点
        {
            for(int j=0;j<=1;j++)//j=0,中心是一个点，j=1,中心是两个点
            {
                int l = i;
                int r = i+j;
                while(l>=0 && r<n && s[l--]==s[r++])num++;
            }
        }
        return num;
    }
    int  spread(const STR& s,int l,int r)
    {
        int count=0;
        int sz=s.size();
        while(l>=0&&r<sz&&s[l]==s[r])
        {
            count+=1;
            l-=1;
            r+=1;
        }
        return count;
    }
    int countSubstrings2(const STR& s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            ans+=spread(s,i,i);
        }
        for(int i=0;i<n-1;++i)
        {
            ans+=spread(s,i,i+1);
        }
        return ans;
    }
};

int main()
{
    STR S{"aaa"};
    cout<<Solution().countSubstrings2(S);
}
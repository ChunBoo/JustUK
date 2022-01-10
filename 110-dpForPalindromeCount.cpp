// return all of the counts of palindromes for a string

#include<string>
#include<iostream>
#include<map>
int countOfPalindromes(const std::string& s, int start,int end)
{
    int sz=s.size();
    if(start>sz||end>sz)
        return false;
    // if(start<0||end<0)
    //     return false;
    if(start>end)
        return true;
    
    if(s[start]==s[end])
        return countOfPalindromes(s,start+1,end-1);
}


int getCountOfPalindromes(const std::string& s)
{
    int sz=s.size();
    if(sz==0||sz==1)
        return sz;
    int ans=0;
    for(int i=0;i<sz;++i)
    {
        for(int j=i;j<sz;++j)
        {
            if(countOfPalindromes(s,i,j))
                ans+=1;
        }
    }
    return ans;
}

int main()
{
    std::string str="racecar";
    int res=getCountOfPalindromes(str);
    std::cout<<res<<'\n';
    return 0;
}
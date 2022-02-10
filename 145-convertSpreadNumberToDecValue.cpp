// change "AA" to the related decimal value,start from 1
#include<string>
#include<iostream>


int convertSpreadSheetValueToDecimalValue(const std::string& s)
{
    int sz=s.size();
    int ans=0;
    if(sz<1)
        return ans;
    for(int i=0;i<sz;++i)
    {
        ans=ans*26+s[i]-'A'+1;
    }

    return ans;
}

int main()
{
    std::string s{"ABC"};
    std::cout<<convertSpreadSheetValueToDecimalValue(s)<<"\n";
    return 0;
}
//hex2dec conversion
#include<iostream>
#include<map>
#include<string>
int hex2dec(const std::string& hex)
{
    int ans=0;
    if(hex.empty())
        return ans;
    
    std::map<char,int> vMap;
    std::map<char,int>::iterator it;
    vMap['A']=10;
    vMap['B']=11;
    vMap['C']=12;
    vMap['D']=13;
    vMap['E']=14;
    vMap['F']=15;

    for(auto temp:hex)
    {
        char i=toupper(temp);
        it=vMap.find(i);
        if(it!=vMap.end())//found the key in map
        {
            ans=ans*16+(it->second);
        }
        else
            ans=ans*16+(i-'0');
    }
    return ans;
}

int main()
{
    std::string hexVal{"ff"};
    int decVal=hex2dec(hexVal);
    std::cout<<hexVal<<" is equal to: "<<decVal<<'\n';
    return 0;
}
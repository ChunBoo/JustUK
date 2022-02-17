// compress the string likes "aabbbccddeeeee"="a2b3c2d2e5"

#include<string>
#include<iostream>
#include<vector>

std::string groupeStrings(const std::string& inString)
{
    std::string retString;
    int sz=inString.size();
    if(sz==0)
        return retString;
    
    // char  preChar;
    int cnt=0;
    for(int i=0;i<sz;++i)
    {   cnt+=1;
        if(inString[i+1]!=inString[i])
        {
            retString+=std::to_string(cnt);
            retString+=inString[i];
            cnt=0;            
        }
        // preChar=inString[i];
    }
    if(cnt>0)
        retString+=std::to_string(cnt);
    return retString;
}


int main()
{
    std::string s="aaaacbbbeedd";
    std::string res=groupeStrings(s);
    std::cout<<res<<'\n';
    return 0;
}
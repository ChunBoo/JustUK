//given one string,to check if those chars can be a panlindrom 
// basic method,check each char's count,if one char's count is odd and larger than 1,than can not be a panlindrom

#include<iostream>
#include<string>
#include<map>
bool check(const std::string& s)
{
    if(s.empty()||s.size()==1 )
        return true;
    std::map<char,int> countMap{};

    for(auto i:s)
    {
        auto search=countMap.find(i);
        if(search!=countMap.end())
            countMap[i]+=1;
        else    
            countMap[i]=1;
    }

    //traverse the map again
    int oddCnt=0;
    for(auto i: countMap)
    {
        int cnt=i.second;
        if(cnt&1==1)  //judge current value is odd
        {   
            oddCnt++;
            if(oddCnt>1)
                return false;
        }
    }
    return true;
}


int main()
{
    std::string s{"nonoaab"};
    bool retValue=check(s);
    std::cout<<s<<" is a panlindrome?"<<(retValue?"Yes":"No")<<'\n';
    return 0;
}
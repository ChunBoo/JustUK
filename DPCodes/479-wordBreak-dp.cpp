#include<vector>  
#include<iostream>
#include<string>
#include<set>   //since std::set is hash map, more faster when looking up
#include<algorithm>
using STR=std::string;
using VEC=std::vector<bool>;
using ST=std::set<STR>;

bool wordsBreak(const STR& s, const std::vector<STR>& wordsDict)
{
    //ST st{wordsDict.begin(),wordsDict.end()};
    int sz=s.size();
    VEC dp(sz+1,false);
    dp[0]=true;

    for(int i=1;i<sz+1;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(dp[j])
            {
                STR tmp=s.substr(j,i-j);
                auto search=std::find(wordsDict.begin(),wordsDict.end(),tmp);
                if(search!=std::end(wordsDict))
                {
                    dp[i]=true;
                    break;
                }
            }
        }
    }
    return dp[sz];
}

int main()
{
    STR s = "applepenapple";
    std::vector<STR> w{"apple","pen"};
    std::cout<<wordsBreak(s,w);

}
//given a fixed coins,likes [1,5,10,25],and target sum value,to return the minimum counts of coins for this targeted value

#include<vector>
#include<iostream>
#include<algorithm>

int countOfCoins(std::vector<int>& coins, std::vector<int>& res, int Value)  //greedy algorithm
{
    if(coins.empty())
        return 0;

    if(Value<=0)
        return 0;
    
    std::sort(coins.begin(),coins.end(),std::greater<int>());  //sorted the coins list from bigger to smaller
    int ans=0;
    for(auto c:coins)
    {
        int cnt=Value/c;
        if(cnt)
            res.push_back(c);
        ans+=cnt;
        Value-=cnt*c;
        if(Value==0)
            break;
    }
    return ans;  
}


int main()
{
    std::vector<int> coins{1,5,10,25};
    std::vector<int> res;
    int value=12;
    std::cout<<countOfCoins(coins,res,value)<<'\n';
    for(auto c:res)
        std::cout<<c<<',';
    return 0;
}
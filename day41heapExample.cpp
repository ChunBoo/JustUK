//greedy algo using heap or priority queue
// list the smallest cost for merging 
#include<queue>
#include<iostream>
#include<vector>
#include<functional>
int smallestCost()
{
        std::vector<int> nums{1,2,3};
    int cost=0;
    if(nums.empty())
        return cost;
    
    std::priority_queue<int,std::vector<int>,std::greater<int>> q;
    for(auto i: nums)
        q.push(i);
    // std::priority_queue<int,std::vector<int>,std::greater<int>> q(nums.begin(),nums.end());

    while(!q.empty())
    {
        int a=q.top();
        q.pop();
        int b=q.top();
        q.pop();
        cost+=(a+b);
        if(q.empty())
            return cost;
        q.push(a+b);
    } 
    return cost;
}

int main()
{

    int retCost=smallestCost();
    std::cout<<"smallest cost is: "<<retCost<<'\n';
    return 0;
}


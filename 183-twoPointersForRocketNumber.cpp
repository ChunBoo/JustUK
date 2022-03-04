//given a list of ints,each number is the weight of human, 
//and there is a limit value,likes 400, means the max weight of rocket can take

#include<vector>
#include<iostream>
#include<algorithm>

int twoPointersForMinCountOfRocketNumber(std::vector<int>& nums, int limit)
{
    if(nums.empty())
        return 0;
    
    std::sort(nums.begin(),nums.end());
    int sz=nums.size();
    int start=0,end=sz-1;
    int ans=0;
    while (start<=end)
    {
        int w=nums[end];
        end-=1;
        if(w+nums[start]<=limit)
        {   
           std::cout<<w<<","<<nums[start]<<'\n';
           start+=1;        
        }
        ans+=1;
    }
    return ans;
}

int main()
{
    std::vector<int> weights{100,180,200,400,250};
    std::cout<<twoPointersForMinCountOfRocketNumber(weights,400)<<'\n';
    return 0;
}

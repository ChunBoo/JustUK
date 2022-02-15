//unbounded knapsack issue,used dp

#include<iostream>
#include<vector>

int getMethods(const std::vector<int>& nums,int n,std::vector<int>& r)  //top2bottom
{
    int ans=0;
    if(n<0)
        return 0;
    if(n==0)
    {
        r.push_back(9);
        return 1;
    }

    for(auto i:nums)
    {   
        if(i>2)
            break;
        r.push_back(i);
        ans+=getMethods(nums,n-i,r);
    }
    return ans;  
}



int main()
{
    std::vector<int> nums{1,2,3,4};
    std::vector<int> rVector{};
    int target=4;
    
    int res=0;
    res=getMethods(nums,target,rVector);
    std::cout<<res<<'\n';
    for(auto i:rVector)
    {
        if(9==i)
            std::cout<<'\n';
        else
            std::cout<<(i);
    }
        
    return 0;
}


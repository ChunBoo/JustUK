//unbounded knapsack issue,used dp

#include<iostream>
#include<vector>

int getMethod2(const std::vector<int>& nums,int Target)   //bottom2top
{
    if(Target<0)
        return 0;
    if(Target==0)
        return 1;
    std::vector<int> dp(Target+1,0);
    dp[0]=1;   //this step is important!!!
    for(int i=1;i<Target+1;++i)
    {
        for(auto j:nums)
        {
            if(i>=j)
            {
                dp[i]+=dp[i-j];
            }
        }
    }
    return dp[Target];
     
}


int getMethods(const std::vector<int>& nums,int n,std::vector<int>& r)  //top2bottom
{
    std::cout<<"n= "<<n<<'\n';
    int ans=0;
    // if(n<0)
    //     return 0;
    if(n==0)
    {
        r.push_back(9);
        return 1;
    }

    for(auto i:nums)
    {   
        // if(i>2)
        //     break;
        r.push_back(i);
        if(i<=n)
            ans+=getMethods(nums,n-i,r);
    }
    return ans;  
}



int main()
{
    std::vector<int> nums{1,2,3};
    std::vector<int> rVector{};
    int target=4;
    
    int res=0;
    res=getMethods(nums,target,rVector);
    // res=getMethod2(nums,target);
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


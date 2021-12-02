// check a list if has pythagorean numbers

#include<iostream>
#include<vector>
#include<algorithm>  //std::sort
#include<functional>  //std::greater

bool isHasPythagoreanInList(std::vector<int>& nums)
{
    if(nums.size()<3)
        return false;

    std::sort(nums.begin(),nums.end());

    int sz=nums.size();

    int n=sz-1;
    for(int i=n;i>0;--i)
    {
        int j=i-1;
        int k=0;

        while(j>k)
        {        
            int c=nums[i]*nums[i];
            int b=nums[j]*nums[j];
            int a=nums[k]*nums[k];
                if(c==(a+b))
                return true;
            if(c<(a+b))
            {
                j-=1;
            }
            else
                k+=1;
        }
    }
    return false;
}

int main()
{
    std::vector<int> nums{1,2,3,4,6};
    std::cout<<isHasPythagoreanInList(nums)<<'\n';
    return 0;
}
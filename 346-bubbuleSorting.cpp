#include<iostream>
#include<vector>

using DT=std::vector<int>;

void bubbleSort(DT& nums)
{
    int len=nums.size();
    if(len==0)
        return ;

    for(int i=0;i<len;++i)
    {
        bool swapped=false;

        for(int j=0;j<len-i-1;++j)
        {
            if(nums[j]>nums[j+1])
            {
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
                swapped=true;
            }
        }
        if(!swapped)
            break;
    }
}

int main()
{
    DT nums{3,5,2,9,1,6};
    bubbleSort(nums);
    for(auto i:nums)
        std::cout<<i<<',';
    return 0;
}
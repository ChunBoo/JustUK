#include<iostream>
#include<algorithm>
#include<vector>

using std::cout;
using VEC=std::vector<int>;

int gMIN(int a,int b){return std::min(a,b);};
int gMAX(int a,int b){return std::max(a,b);};


int minMaxValue( VEC& nums)
{
    int n=nums.size();
    auto g=gMIN;
    while(n>1)
    {
        for(int i=0;i<n/2;++i)
        {
            nums[i]=g(nums[i*2],nums[i*2+1]);
           g=(g==gMIN)?gMAX:gMIN;
        //    if(g==gMIN)
        //         g=gMAX;
        //    else
        //         g=gMIN;
        }
        n/=2;
    }
    return nums[0];
}

int main()
{
    VEC nums{1,2,3,4,5,6,7,8};
    cout<<minMaxValue(nums);
}

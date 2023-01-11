#include<vector>
#include<iostream>
#include<algorithm>


using VEC=std::vector<int>;

bool check(const VEC& piles,int h,int r)
{
    int ans=0;
    for(auto &p:piles)
    {
        if((p%r)!=0)
            ans+=(p/r)+1;
        else
            ans+=(p/r);
    }
    if(ans<=h)
        return true;
    return false;
}

int minEatingSpeed(const VEC& piles,int h)
{
    int start=1;
    int max=*std::max_element(piles.begin(),piles.end());
    int end=max;
    while(start<end)
    {
        int mid=start+(end-start)/2;
        if(check(piles,h,mid))
            end=mid;
        else
            start=mid+1;
    }
    return end;  //here also can return start, as they are same values
}

int main()
{
    VEC piles{30,11,23,4,20};//{3,6,7,11};//{30,11,23,4,20};
    int h=5;//8;//6;
    std::cout<<minEatingSpeed(piles,h);
}
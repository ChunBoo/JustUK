//given one sorted array and new value, return the index of this new value in array
#include<iostream>
#include<vector>

using DT=std::vector<int>;

int bisect_left(const DT& a,int val)
{
    if(a.empty())
        return 0;
    int sz=a.size();
    for(int i=0;i<sz;++i)
    {
        if(a[i]>=val)
            return i;
    }
    return sz;
}

int bisect_right(const DT& a,int val)
{
    if(a.empty())
        return 0;

    int sz=a.size();
    for(int i=0;i<sz;++i)
    {
        if(a[i]>val)
            return i;
    }
    return sz;
}

int bisect_right(const DT& a,int val,int lo=0,int hi=0)
{
    if(lo<0)
        return -1;
    if(hi==0)
        return a.size();
    
    while(lo<hi)
    {
        int mid=lo+(hi-lo)/2;
        if(a[mid]>val)
            mid=hi;
        else
            lo=mid+1;
    }
    return lo;
}

int main()
{
    DT a{1,2,2,3,3,3,4,4,5};
    int idx=bisect_left(a,3);
    // int ridx=bisect_right(a,3);
    int rridx=bisect_right(a,3,6,a.size());
    std::cout<<idx<<'\n';
    // std::cout<<ridx<<'\n';
    std::cout<<rridx<<'\n';
    return 0;
}
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<numeric>
using std::cout;
using VEC=std::vector<int>;

int pickGiftsHeap(VEC& gifts,int k)
{
    std::make_heap(gifts.begin(),gifts.end());
    for(int i=0;i<k;++i)
    {
        std::sort_heap(gifts.begin(),gifts.end());
        int mx=gifts.back();
        // std::pop_heap(gifts.begin(),gifts.end());
        gifts.pop_back();
        gifts.push_back(int(sqrt(mx)));
        std::make_heap(gifts.begin(),gifts.end());
        // std::push_heap(gifts.begin(),gifts.end());
        // std::sort_heap(gifts.begin(),gifts.end(),std::less<int>());
    }
    return std::accumulate(gifts.begin(),gifts.end(),0);
}



int pickGifts(VEC& gifts,int k)
{
    for(int i=0;i<k;++i)
    {
        auto mx= std::max_element(gifts.begin(),gifts.end());
        *mx=int(sqrt(*mx));
    }
    return std::accumulate(gifts.begin(),gifts.end(),0);
}

int main()
{
    VEC gifts{10,1,5,2,9,7,4};
    cout<<pickGifts(gifts,3)<<'\n';
    VEC gifts2{10,1,5,2,9,7,4};

    cout<<pickGiftsHeap(gifts2,3);
}
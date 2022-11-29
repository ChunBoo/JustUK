

#include<vector>
#include<iostream>
using VEC=std::vector<int>;
int maxArea(const VEC& h)
{
    int n=h.size();
    int l=0,r=n-1;
    int ans=0;
    while(l<r)
    {
        ans=std::max(ans,std::min(h[l],h[r])*(r-l));
        if(h[l]<h[r])
            l+=1;
        else
            r-=1;
    }
    return ans;
}

int main()
{
    VEC h{1,8,6,2,5,4,8,3,7};
    std::cout<<maxArea(h);
}
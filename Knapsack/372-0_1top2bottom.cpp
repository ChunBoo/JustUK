#include<vector>
#include<iostream>

using VEC=std::vector<int>;


int ddffs_top2bottom(VEC& w, VEC& v, int c,int i)
{
    if(i==w.size())
        return 0;
    int ans=0;
    if(c>=w[i])
    {
        ans=ddffs_top2bottom(w,v,c-w[i],i+1)+v[i];
        ans=std::max(ans,ddffs_top2bottom(w,v,c,i+1));
    }
    return ans;
}

int main()
{
    VEC v{1,5,3};
    VEC w{1,2,3};

    int res=ddffs_top2bottom(w,v,5,0);
    std::cout<<res;
    return 0;
}
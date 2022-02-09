#include<iostream>
#include<cmath>
#include<vector>
int dpForSplitMaxProduct2(int n)//top2bottom
{
    std::vector<int> nb(n+1,1);
    for(int i=1;i<n+1;++i)
    {
        for(int j=1;j<i;++j)
        {
            int temp=std::max(j*(i-j),j*nb[i-j]);
            nb[i]=std::max(temp,nb[i]);
        }
    }
    return nb[n];
}

int dpForSplitMaxProduct(int n)//top2bottom
{
    if(n<=2)
        return 1;
    if(n==3)
        return 2;
    int ans=1;
    for(int i=1;i<=n;++i)
    {
        int temp=std::max(i*(n-i),i*dpForSplitMaxProduct(n-i));  //O(N*N)
        ans=std::max(temp,ans);
    }
    return ans;
}


int splitMaxProduct(int n) //greedy
{
    if(n<=2)
        return 1;
    if(n==3)
        return 2;
    
    int ans=1;
    while(n>4)
    {
        ans*=3;
        n-=3;
    }
    return ans*n;

}

int main()
{
    std::cout<<dpForSplitMaxProduct2(5)<<'\n';
    return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using std::cout;
using VEC=std::vector<int>;

int pivotInteger(int n)
{
    VEC total(n);
    std::iota(total.begin(),total.end(),1);

    int ss=std::accumulate(total.begin(),total.end(),0);
    int a=0;
    for(int i=n;i>0;--i)
    {
        a+=i;
        if(a==(ss-a+i))
            return i;
    }
    return -1;
}

int pivotIntegerBS(int n)
{
    int L=0,R=n;
    while(L<R)
    {
        int M=(L+R)/2;
        int preSum=(1+M)*(M)/2;
        int postSum=(n+M)*(n-M+1)/2;
        if(preSum==postSum)
            return M;
        else if(preSum<postSum)
            L=M+1;
        else
            R=M-1;
    }
    return -1;
}


int main()
{
    cout<<pivotInteger(8);
    cout<<pivotIntegerBS(8);
}
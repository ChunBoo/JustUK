

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int findIndex(vector<int>& num, int val)
{
    int l=1,r=*max_element(begin(num),end(num));
    while(l<r)
    {
        int m=l+(r-l)/2;
        if(num[m]==val)  //f(m)
            return m;
        if(num[m]>val)
            r=m;
        else
            l=m+1;
    }
    return -1;
}

int lower_boundary(vector<int>& a, int v)
{
    int l=1, r=*max_element(begin(a),end(a));

    while(l<r)
    {
        int m=l+(r-l)/2;
        if(a[m]>=v)
        
    }
}


int main()
{
    vector<int> a{1,2,3,4,5,6};
    int val=7;
    cout<<findIndex(a,val);
}
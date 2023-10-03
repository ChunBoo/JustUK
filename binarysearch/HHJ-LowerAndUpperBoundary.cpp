

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

//lower_bound(x): first index of i, such that a[i]>=x
//upper_bound(x): first index of i, such that a[i]>x

int lower_boundary(vector<int>& a, int v)
{
    int l=1, r=*max_element(begin(a),end(a));

    while(l<r)
    {
        int m=l+(r-l)/2;
        if(a[m]>=v)  //g(m)
            r=m;
        else
            l=m+1;
        
    }
    return l;  //find the smallest index to satisfy(indx)
}
int upper_boundary(vector<int>& a, int v)
{
    int l=1, r=*max_element(begin(a),end(a));

    while(l<r)
    {
        int m=l+(r-l)/2;
        if(a[m]>v)  //g(m)
            r=m;
        else
            l=m+1;
        
    }
    return l;  //find the smallest index to satisfy(indx)
}
int main()
{
    vector<int> a{1,2,2,2,4,4,5};
    cout<<lower_boundary(a,3);
}
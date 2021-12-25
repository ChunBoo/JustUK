//dp 

#include<iostream>
#include<vector>
#include<map>
int getMaxValue(std::vector<int>& vals)
{
    if(vals.empty())
        return 0;
    
    int sz=vals.size();
    if(sz==1)
        return vals[0];
    
    int f0=vals[0];
    int f1=std::max(f0,vals[1]);
    for(int i=2;i<sz;++i)
    {
        int t=f0;
        f1=std::max(f0+vals[i],f1);
        f0=f1;
    }
    return f1;
}

int getMax(std::vector<int>& values,int n,std::map<int,int>& nb)  
{
    if(n<1)
        return 0;
    if(values.empty())
        return 0;
    if(values.size()==1)
        return values[0];

    int f1=values[0];
    int f2=std::max(f1,values[1]);
    // return std::max(values[n-1]+getMax(values,n-2),getMax(values,n-1));
}

int main()
{
    std::vector<int> val{1,7,7};
    int result=getMaxValue(val);
    // int result=getMax(val,3);
    std::cout<<"Result is: "<<result<<'\n';

    return 0;
}
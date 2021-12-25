// count the ways of climb stairs

#include<iostream>
#include<map>
//bottom-up method

int f(int n)
{
    int f1=1,f2=1;
    for(int i=1;i<n;++i)
    {
        int t=f1;
        f1=f2;
        f2=t+f1;
    }
    return f2;
}


int getWaysOfClimbingStairs(int n,std::map<int,int>& nb)
{
    if(n==1)
        return 1;
    if(n==2)
        return 2;
        // return 2;
    std::map<int,int>::iterator it=nb.find(n);
    if(it!=nb.end())
        return nb[n];
    
    int value=getWaysOfClimbingStairs(n-1,nb)+getWaysOfClimbingStairs(n-2,nb);
    // nb.insert(std::pair<int,int>(n,value));
    nb[n]=value;
    return value;
}

int main()
{
    std::map<int,int> nb{};

    // int count=getWaysOfClimbingStairs(4,nb);
    int count=f(4);
    std::cout<<"Count: "<<count<<'\n';

    return 0;
}
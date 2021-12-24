// count the ways of climb stairs

#include<iostream>
#include<map>

int getWaysOfClimbingStairs(int n,std::map<int,int>& nb)
{
    if(n<1)
        return 0;
    if(n==1)
    {
        nb.insert(std::pair<int,int>(1,2));
    }
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

    int count=getWaysOfClimbingStairs(5,nb);
    std::cout<<"Count: "<<count<<'\n';

    return 0;
}
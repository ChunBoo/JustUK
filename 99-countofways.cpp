#include<iostream>
#include<map>

int getCountOfWaysToTarget(int n,int m,std::map<std::pair<int,int>,int>& nb)
{
    if(n==0||m==0)
        return 1;
    std::map<std::pair<int,int>,int>::iterator it;
    it=nb.find(std::pair<int,int>(n,m));
    if(it!=nb.end())
        return it->second;
    int val=getCountOfWaysToTarget(n,m-1,nb)+getCountOfWaysToTarget(n-1,m,nb);
    nb[std::pair<int,int>(n,m)]=val;
    return val;
}

int main()
{
    int n=2,m=3;
    std::map<std::pair<int,int>,int> nb{};
    int count=getCountOfWaysToTarget(1,2,nb);
    std::cout<<"Total count is: "<<count<<'\n';

    return 0;
}
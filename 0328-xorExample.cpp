//xor used to get the single number from a list
#include<iostream>
#include<vector>
int foo(std::vector<int>& list)
{
    if(list.empty())
        return INT_MAX;
    
    int x=0;
    for(auto i:list)
        x^=i;
    return x;
}

int main()
{
    std::vector<int> l{1,1,2,2,3,3};
    std::cout<<foo(l);
    return 0;
}
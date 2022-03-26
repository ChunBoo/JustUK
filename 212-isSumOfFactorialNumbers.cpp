//given a number,return it can be some factorials numbers sum

#include<iostream>
#include<vector>

bool isSumOfFactorialNumbers(int n)
{
    if(n<1)
        return false;

    std::vector<int> val{};
    int x=1,fact=1;
    while(fact<=n)
    {
        fact*=x;
        val.push_back(fact);
        ++x;
    }
    int sz=val.size();
    for(int i=sz-1;i>=0;--i)
    {
        if(n>=val[i])
            n-=val[i];
    }
    return n==0;
}

int main()
{
    std::cout<<isSumOfFactorialNumbers(144);
    return 0;
}
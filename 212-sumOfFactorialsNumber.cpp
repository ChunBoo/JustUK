#include<vector>
#include<iostream>


bool isSumOfFactorials(int n)
{
    if(n<1)
        return false;

    int x=1,fact=1;
    std::vector<int> vecs{};
    while(fact<=n)
    {
        fact*=x;
        vecs.push_back(fact);
        x+=1;
    }

    int len=vecs.size();
    for(int i=len-1;i>=0;--i)
    {
        if(n>=vecs[i])
            n-=vecs[i];
    }
    return n==0;
}

int main()
{
    std::cout<<isSumOfFactorials(4);
    return 0;
}
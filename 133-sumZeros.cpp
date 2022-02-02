#include<iostream>
#include<vector>
std::vector<int> sumZero2(int n)
{
    int i=1;
    long int sum=0;
    std::vector<int> ans;
    while(n>1)
    {
        ans.push_back(i);
        sum+=i;
        i+=1;
        n-=1;
    }
    ans.push_back(-sum);
    return ans;
}


std::vector<int> sumZero(int n)
{
    int i=1;
    std::vector<int> ans;
    while(n>=2)
    {
        ans.push_back(i);
        ans.push_back(-i);
        i+=1;
        n-=2;
    }
    if(n==1)   //n is odd number
        ans.push_back(0);
    return ans;
}

int main()
{
    int n=5;
    std::vector<int> res=sumZero2(n);

    for(auto i:res)
        std::cout<<i<<',';

    return 0;
}

#include<iostream>
#include<vector>

using VEC=std::vector<int>;

VEC SumOfThree(int n)
{
    VEC ans{};
    if(n%3)
        return ans;
    else
    {
        int mid=n/3;
        return VEC{mid-1,mid,mid+1}; 
    }
}

int main()
{
    int n=4;
    VEC res=SumOfThree(n);
    for(auto &v:res)
        std::cout<<v<<',';
    return 0;
}
#include<iostream>
#include<vector>


using VEC=std::vector<int>;

VEC gray(int n)
{
    if(n==1)
        return VEC{0,1};
    VEC prev=gray(n-1);
    int k=1<<(n-1);
    VEC ans{prev.begin(),prev.end()};
    int len=prev.size();
    for(int i=len-1;i>-1;--i)   //here should be reverted seq
    {
        ans.push_back(k+prev[i]);
    }
    return ans;
}

int main()
{
    VEC ans=gray(2);
    for(auto &v:ans)
        std::cout<<v<<',';
}
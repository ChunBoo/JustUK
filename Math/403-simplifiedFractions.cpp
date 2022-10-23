#include<iostream>
#include<string>
#include<vector>

using VEC=std::vector<std::string>;

int gcd(int a,int b)
{
    while(b)
    {
        int tmp=b;
        b=a%b;
        a= tmp;
    }
    return a;
}
VEC simplifiedFractions(int n)
{
    VEC ans{};
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<i;++j)
        {
            if(gcd(j,i)==1)
            {
                std::string tmp=std::to_string(j)+"/"+std::to_string(i);
                ans.push_back(tmp);
            }

        }
    }
    return ans;
}

int main()
{
    int ans=gcd(25,35);
    
    VEC res=simplifiedFractions(6 );
    for(auto v:res)
        std::cout<<v<<',';
        
}
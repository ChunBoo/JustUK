#include<iostream>

typedef  int elem_t;

typedef struct RC
{
    elem_t chickren{};
    elem_t rabbits{};
}rc;

rc solve(const int H,const int L)
{
    rc ans{};
    if(H<1||L<1)
        return ans;
    for(int c=0;c<H+1;++c)
    {
        int r=H-c;
        if((4*r+2*c)==L)
        {
            ans.chickren=c;
            ans.rabbits=r;
        }
    }
    return ans;
}


int main()
{
    rc res=solve(10,24);
    std::cout<<"Chickren: "<<res.chickren<<'\n';
    std::cout<<"Rabbits: "<<res.rabbits<<'\n';
}
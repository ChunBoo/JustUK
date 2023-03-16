#include<iostream>


using std::cout;

int passGame(int n,int time)
{
    int x=1,d=1;
    for(int i=0;i<time;++i)
    {
        x+=d;
        if((x==1) ||(x==n))
            d*=-1;
    }
    return x;
}



int main()
{
    cout<<passGame(4,5);
}
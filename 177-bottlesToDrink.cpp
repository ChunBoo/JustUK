//given a n bottles, which 3x empty bottles can exchange 1 new bottle
#include<iostream>

int drink(int bottles)
{
    int ans=bottles;
    while(bottles>=3)
    {
        int exchange=bottles/3;
        ans+=exchange;
        bottles=(bottles%3)+exchange;
    }
    // int newEmptyBottles=ans;
    // int remainder=0;
    // while(newEmptyBottles>=3)
    // {
    //     newEmptyBottles/=3;
    //     remainder=newEmptyBottles%3;
    //     ans+=newEmptyBottles;
    // }
    // if((remainder+newEmptyBottles)>=3)
    //     ans+=1;
    return ans;
}

int main()
{
    std::cout<<drink(8)<<'\n';
    return 0;
}
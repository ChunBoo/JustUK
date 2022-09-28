

#include<iostream>


int minStepsToReduce(int val)
{
    int ans=0;
    while(val)
    {
        if(val&1)
            val-=1;
        else
            val/=2;
        ans+=1;
    }
    return ans;
}

int main()
{
    std::cout<<minStepsToReduce(5);

}
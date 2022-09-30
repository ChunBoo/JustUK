

#include<iostream>
#include<bitset>
#include<string>
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

int steps(int val)
{
    std::bitset<32> bs(val);
    int ones=bs.count();
    std::string s=bs.to_string();
    size_t pos1=s.find("1");
    int zeros=s.size()-pos1-ones;

    return ones*2+zeros-1;
}

int main()
{
   // std::cout<<minStepsToReduce(15);
    std::cout<<steps(15);

}
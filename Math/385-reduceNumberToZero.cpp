

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
typedef size_t pos_t;
int steps(int val)
{
    std::bitset<32> bs(val);
    std::string s=bs.to_string();
    int ones=bs.count();
    pos_t posOne=s.find("1");
    int zeros=s.size()-posOne-ones;
    return ones*2+zeros-1;
}

int main()
{
    std::cout<<minStepsToReduce(15);
    std::cout<<steps(15);

}
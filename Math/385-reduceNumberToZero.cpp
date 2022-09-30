

#include<iostream>
#include<bitset>
#include<string>
<<<<<<< HEAD
=======

>>>>>>> b81ec9123428abe111cd33a928508e41c57e4797
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
    std::cout<<minStepsToReduce(15);
    std::cout<<steps(15);

}
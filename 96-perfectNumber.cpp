//perfect number 1+2+4+7+14=28
#include<iostream>
#include<vector>


bool isPerfectNumber2(int num)  //O(SQRT(n))
{
    if(num<=0)
        return false;
    
    std::vector<int> p{};
    // int t=num;
    int i=1;
    int sum=0;
    while(i*i<=num)
    {
        if(num%i==0)
        {
            sum+=i;
            if(i*i!=num)
                sum+=num/i;
        }
        ++i;
    }

    return sum-num==num;
}


bool isPerfectNumber(int num)
{
    if(num<=0)
        return false;
    
    std::vector<int> p{};
    int t=num;
    int i=1;
    while(i<=t/2)
    {
        if(t%i==0)
            p.push_back(i);
        ++i;
    }
    int sum=0;
    for(auto i:p)
        sum+=i;

    return sum==num;
}

int main()
{
    int n=28;
    std::cout<<n<<" is perfect number? "<<isPerfectNumber2(n)<<'\n';
    return 0;
}
//given a number,to check if it is  a ugly number: just can be divided by 2/3/5

#include<iostream>
#include<vector>
bool isUlyNumber(int n)
{
    if(n<=0)
        return false;
    
    std::vector<int> P{2,3,5};

    for(auto i:P)
    {
        while(n>0&&n%i==0)
        {
            n/=i;
        }
    }
    return n==1;
}


int main()
{
    int n=49;
    bool ret=isUlyNumber(n);
    std::cout<<n<<" is a ugly number? "<<ret<<'\n';

    return 0;
}
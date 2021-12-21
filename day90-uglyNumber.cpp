
//given a number to check it is a ugly number or not
//ugly number is a number which can just divided by 2,3,5

#include<iostream>
#include<vector>
bool isUglyNumber(int n)
{
    if(n<=0)
        return false;
    
    std::vector<int> P{2,3,5};
    std::vector<int> basicNumber{2,3,5};

    for(auto i:basicNumber)
    {
        while(n>1 && n%i==0)
        {
            n/=i;
        }
    }
    return n==1;
}


int main()
{
    int n=49;
    bool ret=isUglyNumber(n);
    std::cout<<n<<" is a ugly number? "<<ret<<'\n';
int main()
{
    int n=26;
    std::cout<<n<<" is a ugly number? "<<isUglyNumber(n)<<'\n';

    return 0;
}
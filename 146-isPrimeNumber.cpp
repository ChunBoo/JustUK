#include<iostream>
#include<vector>
#include<algorithm>
bool isPrime(int n)//sieve algorithm
{
    std::vector<bool> isPrime(n+1,true);
    int i=2;
    for(;i*2<=n;++i)
    {
        if(isPrime[i])
        {
            int j=i*2;
            while(j<=n)
            {
                isPrime[j]=false;
                j+=i;   //
            }
        }
    }
    return isPrime[n];
}

bool isPrimes(int n)  // O(sqrt(n)) version
{
    bool ans=false;
    if(n<=1)
        return false;
    int i=2;
    while(i*i<=n)  //the boundary check is important!!
    {
        if(n%i==0)
            return false;
        i+=1;
    }
    return true;
}


int main()
{
    int v=20;
    std::vector<int> primesList{};
    for(int i=2;i<v+1;++i)
    {
        if(isPrime(i))
            primesList.push_back(i);
    }

    for(auto i:primesList)
        std::cout<<i<<" ,";

    return 0;
}
#include<iostream>

int sumOfNOddNumber(int n)
{
    return n*n;  //math induction

}


int sumOfOddNumberWithIterator(int n)
{
    int ans=0;
    for(int i=1;i<=2*n;i+=2)
        ans+=i;
    return ans;
}

int sumOfFirstEvenNumber(int n)
{
    return n*(n+1);  //math indcution
}

int sumOfFirstEvenNumberWithIterator(int n)
{
    int ans=0;
    for(int i=2;i<=(2*n);i+=2)
        ans+=i;
    return ans;

}

int main()
{
    int n=3;  //1+3+5
    int sum =sumOfFirstEvenNumberWithIterator(n);

    std::cout<<"Sum of first "<<n<<" odd numbers is: "<<sum<<'\n';
    return 0;

}
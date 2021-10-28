#include<iostream>
//最大公约数和最小公倍数

class Solution
{
    public:
        int getGCD(int a,int b)
        {
            while(b>0)
            {
                int temp=a;
                a=b;
                b=temp%b;
            }
            return a;
        }

        int getLCM(int a,int b)
        {
            return (a*b)/getGCD(a,b);
        }
};


int main()
{
    Solution s;
    int a=12,b=15;
    int ret=s.getGCD(a,b);
    std::cout<<"GCD is: "<<ret<<'\n';
    std::cout<<"LCM is: "<<s.getLCM(a,b)<<'\n';
    
    return 0;
}
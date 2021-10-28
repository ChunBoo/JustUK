#include<iostream>


class Solution
{
    public:
        int inverseFactorial1(int n)
        {
            int ans=-1;
            if(n==1)
                return 1;
            if(n<1)
                return ans;
            
            int i=2;
            while(n>1)
            {
                if(n%i!=0)
                    return -1;
                n/=i;
                i++;
            }
            return i-1;
        }

        int inverseFactorial(int n)
        {
            if(n<1)
                return -1;
            
            int i=2;
            int s=1;
            while(s<n)
            {
                s=s*i;
                i++;
            }
            return s==n?i-1:-1;
        }
};

int main()
{
    Solution s;
    int value=s.inverseFactorial1(7);
    std::cout<<"value= "<<value<<'\n';

    return 0;
}
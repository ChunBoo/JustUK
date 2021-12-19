// happy number is a positive number which 
#include<iostream>
#include<set>
bool isHappyNumber(int n)
{
 if(n==1)
    return true;
 std::set<int> d{};
 while(n!=1 && d.find(n)==d.end())
 {
     d.insert(n);
     int sum=0;
     int cur=n;
     while(cur>0)
     {
         int temp=cur%10;
         sum+=temp*temp;
         cur/=10;
     }
     n=sum;
 }
 return n==1;
}

int main()
{
    int n=9;
    bool res=isHappyNumber(n);
    std::cout<<n<<" is a happynumber? "<<(res?"Yes":"No")<<'\n';

    return 0;
}

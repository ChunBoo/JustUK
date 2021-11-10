//two numbers multiply

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
int multiply(std::string& x,std::string& y,int *result)
{
    long long ans=0;
    int xLength=x.length();
    int yLength=y.length();
    result=new int (xLength+yLength);
    // revert the sequence of x and y
    std::reverse(x.begin(),x.end());
    std::reverse(y.begin(),y.end());
    for(int i=0;i<xLength;++i)
    {
        for(int j=0;j<yLength;++j)
        {
            result[i+j]+=(x[i]-'0')*(y[j]-'0');
            int temp=(x[i]-'0')*(y[j]-'0');
            std::cout<<x[i]-'0'<<'\n';
            std::cout<<y[j]-'0'<<'\n';
            std::cout<<temp<<'\n';
            // std::cout<<result[i+j]<<"-";
            result[i+j+1]+=result[i+j]/10;
            result[i+j]%=10;
        }
    }
    for(int idx=xLength+yLength-1;idx>=0;--idx)
        std::cout<<"Result="<<result[idx]<<'\n';
}

int main()
{
    std::string x{"12"};
    std::string y{"15"};
    int *value{new int};
    multiply(x,y,value);
    // std::cout<<x<<" * "<<y<<" = "<<*value<<"\n";

    return 0;
}
//binary 2 decimal 

#include<iostream>
#include<string>
#include<cstdio>

int b2d(std::string num)  //binary to decimal
{
    int ans=0;
    if(num.empty())
        return ans;
    for(auto i:num)
    {
        ans=ans*2+(i-'0');
    }
    return ans;
}

std::string decimal2binary(int dVal)
{
    std::string ans{};
    while(dVal)
    {
        ans=ans+(static_cast<char>(dVal%2+48));
        dVal=dVal/2;
    }
    return ans;
}

int main()
{
    std::string testStr{"11"};
    int decVal=15;
    // int dValue=b2d(testStr);
    // std::cout<<testStr<<" convert to decimal is: "<<dValue<<'\n';
    std::cout<<testStr<<" convert to decimal is: "<<std::stoi(testStr,nullptr,2)<<'\n';
    // std::cout<<"15 mod 2=: "<<7%2<<"\n";
    std::string binaryNumber=decimal2binary(decVal);
    std::cout<<decVal<<" convert to binary is: "<<binaryNumber<<'\n';

    return 0;
}
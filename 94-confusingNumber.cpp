//confusing number 6->9,9->6,8->8,1->1,0->1

#include<iostream>
#include<string>

bool isConfusingNumber(int n)
{
    std::string s{std::to_string(n)};
    std::string temp{};
    for(auto i:s)
    {
        if(i=='6')
            temp+='9';
        else if(i=='9')
            temp+='6';
        else if(i=='0'||i=='1')
            temp+=i;
    }
    
}

int main()
{
    int d=123;
    std::string s{std::to_string(d)};
    // std::cout<<"string s: "<<s<<'\n';
    for(auto i:s)
        std::cout<<i<<'-';
    return 0;
}
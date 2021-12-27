//confusing number 6->9,9->6,8->8,1->1,0->1

#include<iostream>
#include<string>

char convert(char i)
{
    if(i=='6')
        return '9';
    else if(i=='9')
        return '6';
    else if(i=='0'||i=='1'||i=='8')
        return i;
    return '-1';

}

bool isConfusingNumber(int n)
{
    std::string s{std::to_string(n)};
    std::string temp{};
    for(auto i:s)
    {
        char newChar=convert(i);
        if(newChar=='-1')
            return false;
        temp+=newChar;
    }
    std::cout<<"temp number is:"<<temp<<'\n';
    return temp!=s;
}

int main()
{
    int num=10986;
    bool confusingNumber=isConfusingNumber(num);
    std::cout<<num<<" is a confusing number? "<<!confusingNumber<<'\n';
    return 0;
}

// int main()
// {
//     int d=123;
//     std::string s{std::to_string(d)};
//     // std::cout<<"string s: "<<s<<'\n';
//     for(auto i:s)
//         std::cout<<i<<'-';
//     return 0;
// }
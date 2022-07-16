#include<string>
#include<iostream>
#include<stack>
std::string addNumbers(std::string& a, std::string& b)
{
    std::string ans{};
    int n1=a.size()-1,n2=b.size()-1;
    int c=0;
    std::stack<int> s{};
    while(n1>=0||n2>=0||c>0)
    {
        int x=c;
        if(n1>=0)
        {
            x+=a[n1]-'0';
            n1-=1;
        }
        if(n2>=0)
        {
            x+=b[n2]-'0';
            n2-=1;
        }
        s.push(x%10);
        c=x/10;
    }
    while(!s.empty())
    {
        ans+=(s.top()+'0');
        s.pop();
    }
    return ans;
}

int main()
{
    std::string a="123",b={"49"};
    std::cout<<addNumbers(a,b);
    return 0;
}
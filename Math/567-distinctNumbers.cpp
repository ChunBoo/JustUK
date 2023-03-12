#include<iostream>
#include<set>

using std::cout;
using SET=std::set<int>;


void foo(int n,SET& seen)
{

    for(int i=2;i<n;++i)
    {
        if((n%i)==1&&(seen.find(i)==seen.end()))
        {
            seen.insert(i);
            foo(i,seen);
        }
    }
}

int distinctInteger(int n)
{
    SET seen{};
    if(n<=2)
        return 1;
    seen.insert(n);
    foo(n,seen);
    return seen.size();
}

int main()
{
    cout<<distinctInteger(5);
}
#include<iostream>
#include<stack>


struct Element
{
    int n;
    char from;
    char to;
    char via;
};

using std::cout;
using STACK=std::stack<Element>;

void hanoi_non_recursive(int n,char from,char to,char via)
{
    STACK elements;
    elements.push({n,from,to,via});
    while(!elements.empty())
    {
        auto element=elements.top();
        elements.pop();
        n=element.n;
        from=element.from;
        to=element.to;
        via=element.via;
        if(n==1)
        {
            cout<<from<<" -> "<<to<<'\n';
        }
        else
        {
            elements.push({n-1,via,to,from});
            elements.push({1,from,to,via});
            elements.push({n-1,from,via,to});
        }
    }
}

int main()
{
    hanoi_non_recursive(3,'A','C','B');
}
#include<iostream>
#include<stack>

using std::cout;

void hanoi_non_recursive(int n,char from,char to,char via)
{
    struct Element
    {
        int n;
        char from;
        char to;
        char via;
    };
    using STACK=std::stack<Element>;
    STACK elements;
    elements.push({n,from,to,via});
    while(!elements.empty())
    {
        Element top=elements.top();
        elements.pop();
        n=top.n;
        from=top.from;
        to=top.to;
        via=top.via;
        if(n==1)
            cout<<from<<" -> "<<to<<'\n';
        else
        {   //stack is LIFO,so we should push the first step to bottom of stack
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
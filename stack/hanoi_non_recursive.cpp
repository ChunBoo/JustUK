#include<iostream>
#include<stack>

using std::cout;

void hanoi_non_recursive(int n,char from,char to,char via)
{
    struct Element
    {
        int n;
        char from,to,via;
    };
    std::stack<Element> st;
    st.push({n,from,to,via});
    while(!st.empty())
    {
        Element cur=st.top();
        st.pop();
        int n=cur.n;
        char from=cur.from;
        char to=cur.to;
        char via=cur.via;
        if(n==1)
            cout<<from<<" -> "<<to<<'\n';
        else
        {
             //stack is LIFO,so we should push the first step to bottom of stack
            st.push({n-1,via,to,from});
            st.push({1,from,to,via});
            st.push({n-1,from,via,to});
        }
    }
}

int main()
{
    hanoi_non_recursive(3,'A','C','B');
}
#include<stack>
#include<vector>
#include<iostream>
#include<algorithm>
using VEC=std::vector<int>;
using STACK=std::stack<int>;

bool checkSequence(VEC& pushed, VEC& popped)
{
    int i=0;
    STACK st{};
    for(auto &v:pushed)
    {
        st.push(v);
        while(!st.empty() &&i<popped.size() &&st.top()==popped[i])
        {
            st.pop();
            i+=1;
        }
    }
    return st.empty();
}

int main()
{
    VEC pushed{1,2,3,4,5},popped{5,4,3,2,1};
    std::cout<<checkSequence(pushed,popped);

}
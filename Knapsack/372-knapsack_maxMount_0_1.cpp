/*
 given two lists of integers weights and values which have the same length and an integer capacity. weights[i] and values[i] represent the weight and value of the ith item. Given that you can take at most capacity weights, and that you can only take at most one copy of each item, return the maximum amount of value you can get.

Constraints
n ≤ 250 where n is the length of weights and values
capacity ≤ 250

Example 1
Input
weights = [1, 2, 3]
values = [1, 5, 3]
capacity = 5
Output
8
Similar to original knapsack, but how do you ensure the specific element is only included once?
*/

#include<vector>
#include<iostream>


using VEC=std::vector<int>;

int dfs(VEC& w, VEC& vals,int Capacity,int i)
{
    int sz=w.size();
    if(i>=sz)
        return 0;
    int ans=0;
    if(Capacity>=w[i])
    {
        ans=std::max(ans,dfs(w,vals,Capacity-w[i],i+1)+vals[i]);
        ans=std::max(ans,dfs(w,vals,Capacity,i+1));
    }
    return ans;
}

int main()
{
    VEC w{1,2,3},v{1,5,3};
    int res=dfs(w,v,5,0);
    std::cout<<res;
    return 0;
}
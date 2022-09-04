
/*

You have some coins. The i-th coin has a probability prob[i] of facing heads when tossed.

Return the probability that the number of coins facing heads equals target if you toss every coin exactly once.

Example 1:
Input: prob = [0.4], target = 1
Output: 0.40000

Example 2:
Input: prob = [0.5,0.5,0.5,0.5,0.5], target = 0
Output: 0.03125

Hints:
What about solving the problem with DP?
Use DP with two states dp[pos][cnt], where pos represents the pos-th coin and cnt is the number of heads seen so far.
You can do the transitions with a little bit math.
For the base case, when pos == n return (cnt == target) to filter out the invalid scenarios.*/


#include<iostream>
#include<vector>

using VEC=std::vector<float>;

float dfs(int i, int target,VEC& p)
{
    if(i==p.size())
        return target==0;

    float choose=dfs(i+1,target-1,p)*p[i];
    float skip=dfs(i+1,target,p)*(1-p[i]);
    return choose+skip;
}

int main()
{
    VEC p{0.5,0.5,0.5,0.5,0.5};
    float res=dfs(0,5,p);
    std::cout<<res;
}
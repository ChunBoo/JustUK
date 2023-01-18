/*

Recursive Determination of Derangements
We now consider derangements recursively. That is, by knowing the few easy-to-calculate values for derangements of small numbers of objects, can we determine a pattern for the number of derangements of larger numbers of elements?

Suppose we want to determine the number of derangements of the n integers 1,2,...,n for n bigger than 2. Let us focus on k and move it into the first position. We thus have started a derangement, for 1 is not in its natural position. Where could 1 be placed? There are two cases we could consider: either 1 is in position k or 1 is not in position k.

If 1 is in position k, here's what we know: The integers 1 and k have simply traded positions.

Prohibited Value
1
2
3
...
k-1
k
k+1
...
n
Derangement
k
?
?
...
?
1
?
...
?
Indicated by the question marks, there are (n-2) integers yet to derange. This can be done in D(n-2) ways.

If 1 is not in position k, we don't know as much. Note that we have shown 1 as a prohibited value twice. This is required for this case, because we cannot have 1 appear in the first position (its natural position) nor can 1 appear in position k.

Prohibited Value
1
2
3
...
k-1
1
k+1
...
n
Derangement
k
?
?
...
?
?
?
...
?
Indicated by the question marks, there are now (n-1) integers yet to derange. This can be done in D(n-1) ways.

Putting this together, we have D(n-1) + D(n-2) possible derangements when k is in the first position. How many different integers could we put in position 1 and carry out this process? All the integers except 1. that is, (n-1) different integers.

This yields the recursive formula D(n) = (n-1)[D(n-1) + D(n-2)]. As long as we know D(1) = 0 and D(2) = 1, we can generate subsequent values for D(n).

*/
#include<iostream>
#include<vector>


using VEC=std::vector<int>;

int derangement(int n)
{
    if(n==0 ||n==1)
        return 0;
    if(n==2)
        return 1;

    VEC dp(n+1,0);
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;++i)
    {
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}

int derangement2(int n)
{
    if(n==0 ||n==1)
        return 0;
    if(n==2)
        return 1;
    int a=0,b=1;
    for(int i=3;i<=n;++i)
    {
        int cur=(i-1)*(a+b);
        a=b;
        b=cur;
    }
    return b;
}

int main()
{
    std::cout<<derangement(4)<<'\n';
    std::cout<<derangement2(4)<<'\n';
}
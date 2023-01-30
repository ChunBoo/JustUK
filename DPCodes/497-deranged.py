

"""
DERANGEMENT ALGORITHM VIA RECURSION
Let’s - (!3+3)*!3=10 - Derangement Algorithms via Dynamic Programming Algorithm algorithms dynamic programming Dynamic Programming math python   youtube video  to denote the number of ways to put N items in such derangement order aka the i-th item cannot be put in index i. The base conditions are:

tex_6398b0b40d7d71c62de8fad787239985   - (!3+3)*!3=10 - Derangement Algorithms via Dynamic Programming Algorithm algorithms dynamic programming Dynamic Programming math python   youtube video 
tex_e05fefefa8d559dbd4453ad2798c0cb1   - (!3+3)*!3=10 - Derangement Algorithms via Dynamic Programming Algorithm algorithms dynamic programming Dynamic Programming math python   youtube video 

Now, let’s take a look at the item N. We cannot place it in the last position but we can put it at position 1 to N-1 so N-1 choices.
If we put it at K where K is not N, then we have two choices for K, we can swap it with N thus tex_42b0296b8359c0062b284e87b5d0d865   - (!3+3)*!3=10 - Derangement Algorithms via Dynamic Programming Algorithm algorithms dynamic programming Dynamic Programming math python   youtube video  or we don’t, thus tex_59c7454ce8f4b698ac032c4b8019eeb5   - (!3+3)*!3=10 - Derangement Algorithms via Dynamic Programming Algorithm algorithms dynamic programming Dynamic Programming math python   youtube video 

    - (!3+3)*!3=10 - Derangement Algorithms via Dynamic Programming Algorithm algorithms dynamic programming Dynamic Programming math python   youtube video 
so further simplified to:
tex_2608a59b4e3a25425bb419466b9d7c41   - (!3+3)*!3=10 - Derangement Algorithms via Dynamic Programming Algorithm algorithms dynamic programming Dynamic Programming math python   youtube video 

Thus, recursive algorithm similar to Fibonacci numbers which can be done in simple Recursion:

1
2
3
4
5
6
def f(n):
    if n in (0, 1):
        return 0
    if n == 2:
        return 1
    return (n - 1) * (f(n-1) + f(n-2))
The time complexity is exponential since we re-calculate the intermediate f values.

DERANGEMENT ALGORITHM VIA DYNAMIC PROGRAMMING
We can simply add a @cache keyword or use a hash map aka dictionary to remember the values so that are not calculated over and over again. This is Top Down Dynamic Programming Algorithm aka Recursion with Memoization:

1
2
3
4
5
6
7
@cache
def f(n):
    if n in (0, 1):
        return 0
    if n == 2:
        return 1
    return (n - 1) * (f(n-1) + f(n-2))
The Dynamic Programming algorithm can be done in Bottom Up manner. Below uses the Array to calculate and store the derangement values from a smaller N e.g. F(0), F(1), F(2) … F(N)

1
2
3
4
5
6
7
8
9
10
def f(n):
    if n in (0, 1):
        return 0
    if n == 2:
        return 1
    dp = [0] * (n + 1)
    dp[2] = 1
    for i in range(3, n + 1):
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2])
    return dp[-1] # or dp[n]
The time/space complexity is O(N). The f(n) value is only dependent on f(n-1) and f(n-2) the previous two values, similar to Fibonacci Numbers, and thus we can use two variables to store these:

1
2
3
4
5
6
7
8
9
def f(n):
    if n in (0, 1):
        return 0
    if n == 2:
        return 1
    a, b = 0, 1
    for i in range(3, n + 1):
        a, b = b, (a + b) * (i - 1)
    return b
"""
def f(n):
    if n in (0,1):
        return 0
    if n==2:
        return 1
    return (n-1)*(f(n-1)+f(n-2))

def derangment(n):
    der=[0]*(n+1)
    der[0]=0
    der[1]=0
    der[2]=1
    for i in range(3,n+1):
        der[i]=(i-1)*(der[i-1]+der[i-2])
    return der[n]

def derangment2(n):
    if n in (0,1):
        return 0
    if n==2:
        return 1
    a,b=0,1
    for i in range(3,n+1):
        a,b=b,(i-1)*(a+b)
    return b
print(f(3))
print(derangment(3))
print(derangment2(3))
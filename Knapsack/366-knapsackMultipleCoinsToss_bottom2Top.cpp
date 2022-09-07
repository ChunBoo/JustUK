 #include<iostream>
 #include<vector>

 using VEC=std::vector<float>;

 float coins_b2t(int target, VEC& p)
 {
    if(target>p.size())
        return 0;
    int n=p.size();
    std::vector<std::vector<float>> dp(n,std::vector<float>(target,0));
    dp[0][0]=1-p[0];
    dp[0][1]=p[0];

    for(int i=1;i<n;++i)
    {
        for(int j=0;j<=target;++j)
        {
            dp[i][j]=p[i]*dp[i-1][j-1]+(1-p[i])*dp[i-1][j];
        }
    }
    return dp[n-1][target];
 }

 int main()
 {
    VEC p{0.5,0.5,0.5,0.5,0.5};
    std::cout<<coins_b2t(5,p);
 }



# Python3 program for maximum average
# sum partition
def largestSumOfAverages(A, K):

	n = len(A);

	# storing prefix sums
	pre_sum = [0] * (n + 1);
	pre_sum[0] = 0;
	for i in range(n):
		pre_sum[i + 1] = pre_sum[i] + A[i];

	# for each i to n storing averages
	dp = [0] * n;
	sum = 0;
	for i in range(n):
		dp[i] = (pre_sum[n] -
				pre_sum[i]) / (n - i);
	
	for k in range(K - 1):
		for i in range(n):
			for j in range(i + 1, n):
				dp[i] = max(dp[i], (pre_sum[j] -
									pre_sum[i]) /
									(j - i) + dp[j]);
	
	return int(dp[0]);

# Driver code
A = [ 9, 1, 2, 3, 9 ];
K = 3; # atmost partitioning size
print(largestSumOfAverages(A, K));

# This code is contributed by Rajput-Ji

def largestSumOfAverages(nums,K):
    n=len(nums)
    
    sum=[0.0]*(n+1)
    
    for i in range(1,n+1):
        sum[i]=nums[i-1]+sum[i-1]
        
    dp=[[0.0]*(K+1)]*(n+1)
    
    for i in range(1,n+1):
        dp[i][1]=float(sum[i]/i)
    
    for i in range(1,n+1):
        for k in range(2,K+1):
            for j in range(1,i):
                dp[i][k]=max(dp[i][k],dp[j][k-1]+float((sum[i]-sum[j])//(i-j)))
    
    return dp[n][K]

# nums = [9,1,2,3,9]
# k = 3

# print(largestSumOfAverages(nums,k))
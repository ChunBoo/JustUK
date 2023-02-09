#include<iostream>
#include<vector>

using VEC=std::vector<int>;
using std::cout;
using MATRIX=std::vector<VEC>;

int f(const VEC& nums)
{
	int n=nums.size();
	if(!n)
			return 0;
	if(n==1)
			return nums[0];
	if(n==2)
			return std::max(nums[0],nums[1]);
	int a=nums[0],b=std::max(nums[0],nums[1]);
	for(int i=2;i<n;++i)
	{
		int tmp=std::max(nums[i]+a,b);
		a=b;
		b=tmp;
	}
	return b;
}
int largestSum(const MATRIX& nums)
{
 	int ans{};
	VEC tmp{};
	for(auto &n:nums)
	{
		tmp.push_back(f(n));
	}
	return f(tmp);
}

int main()
{
	
	MATRIX matrix {
		{1, 7, 6, 5},
		{9, 9, 3, 1},
		{4, 8, 1, 2}
		};
	cout<<largestSum(matrix);
}

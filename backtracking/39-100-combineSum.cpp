#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;

void test(MATRIX& ret,VEC& nums,int target,int idx,int sum,VEC cur)
{
	if(target<sum || idx==nums.size())
		return;
	if(target==sum)
	{
		ret.push_back(cur);
		return;
	}
	for(int j=idx;j<nums.size();++j)
	{
		// if(sum+nums[j]>target)
		// 	break;
		// VEC tmp{cur};
		// tmp.push_back(nums[j]);
		cur.push_back(nums[j]);
		test(ret,nums,target,idx+1,sum+nums[j],cur);
	}
}


MATRIX testSum(VEC nums,int target)
{
	MATRIX ans{};
	VEC cur{};
	std::sort(nums.begin(),nums.end());
	test(ans,nums,target,0,0,cur);
	return ans;
	
}

int main()
{
	VEC candidates{2,3,6,7};
	int target = 7;
	MATRIX ret=testSum(candidates,target);
	for(auto &_:ret)
	{
		cout<<'[';
		for(auto c:_)
			cout<<c<<',';
		cout<<']';
	}
}

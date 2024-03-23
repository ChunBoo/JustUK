#include<iostream>
#include<set>

using std::cout;
using SET=std::set<int>;


void foo(int n,SET& seen)
{

    for(int i=2;i<n;++i)
    {
        if((n%i)==1&&(seen.find(i)==seen.end()))
        {
            seen.insert(i);
            foo(i,seen);
        }
    }
}

int distinctInteger(int n)
{
    SET seen{};
    if(n<=2)
        return 1;
    seen.insert(n);
    foo(n,seen);
    return seen.size();
}
/**
 * @brief 我们使用数组 nums\textit{nums}nums 记录桌面上已经出现的正整数，初始时 nums[n]=1\textit{nums}[n] = 1nums[n]=1 表示桌面上只出现正整数 nnn。

每天都对桌面上已出现的数字进行遍历，对于当前遍历的数字 xxx，枚举正整数 i∈[1,n]i \in [1, n]i∈[1,n]，如果 x mod i=1x \bmod i = 1xmodi=1，那么令 nums[i]=1\textit{nums}[i] = 1nums[i]=1，即将数字 iii 放到桌面上。最后统计 nums\textit{nums}nums 中值为 111 的元素数目即可。


 * 
 */
class Solution {
public:
    int distinctIntegers(int n) {
        // return n>1?n-1:1;
        vector<int> nums(n+1);
        nums[n]=1;
        for(int i=0;i<n;i++){
            for(int x=1;x<=n;x++){
                if(nums[x]==0)
                    continue;
                for(int j=1;j<=n;j++)
                    if(x%j==1)
                        nums[j]=1;
            }
        }
        return accumulate(nums.begin(),nums.end(),0);
    }
};

int main()
{
    cout<<distinctInteger(5);
}
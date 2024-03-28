/**
 * @file 2-1997-firstDayBeenInAllRooms.cpp
 * 
 * 
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-28
 * 
 * @copyright Copyright (c) 2024
 * 
 * There are n rooms you need to visit, labeled from 0 to n - 1. Each day is labeled, starting from 0. You will go in and visit one room a day.

Initially on day 0, you visit room 0. The order you visit the rooms for the coming days is determined by the following rules and a given 0-indexed array nextVisit of length n:

Assuming that on a day, you visit room i,
if you have been in room i an odd number of times (including the current visit), on the next day you will visit a room with a lower or equal room number specified by nextVisit[i] where 0 <= nextVisit[i] <= i;
if you have been in room i an even number of times (including the current visit), on the next day you will visit room (i + 1) mod n.
Return the label of the first day where you have been in all the rooms. It can be shown that such a day exists. Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: nextVisit = [0,0]
Output: 2
Explanation:
- On day 0, you visit room 0. The total times you have been in room 0 is 1, which is odd.
  On the next day you will visit room nextVisit[0] = 0
- On day 1, you visit room 0, The total times you have been in room 0 is 2, which is even.
  On the next day you will visit room (0 + 1) mod 2 = 1
- On day 2, you visit room 1. This is the first day where you have been in all the rooms.
Example 2:

Input: nextVisit = [0,0,2]
Output: 6
Explanation:
Your room visiting order for each day is: [0,0,1,0,0,1,2,...].
Day 6 is the first day where you have been in all the rooms.
Example 3:

Input: nextVisit = [0,1,2,0]
Output: 6
Explanation:
Your room visiting order for each day is: [0,0,1,1,2,2,3,...].
Day 6 is the first day where you have been in all the rooms.
 

Constraints:

n == nextVisit.length
2 <= n <= 105
0 <= nextVisit[i] <= i
 * 
 */


/**
 * @brief 
 * 根据题意，首次访问房间 iii 时，因为我们是第一次访问，111 是奇数，所以下一天一定要访问 j=nextVisit[i]j=\textit{nextVisit}[i]j=nextVisit[i] 房间，下文简称为「回访」。

由于访问偶数次才能访问右边的下一个房间，所以对于 iii 左边的房间，我们一定都访问了偶数次（不然不可能到达 iii）。

这意味着，当我们从 iii 回到 jjj 时，此时 [j,i−1][j,i-1][j,i−1] 范围内的房间都处于访问偶数次的状态。那么当我们访问这个范围内的每个房间时，算上本次访问，访问次数一定是奇数，所以要想重新回到 iii，对于 [j,i−1][j,i-1][j,i−1] 范围内的每个房间，我们都需要执行一次「回访」。

状态设计
对于房间 iii，其访问次数的奇偶性变化如下表：

描述	奇偶性
访问房间 iii 之前	偶数
访问到房间 iii	奇数
回访完毕，重新回到房间 iii	偶数
这说明从「访问到房间 iii 且次数为奇数」到「访问到房间 iii 且次数为偶数」是一个完整的周期，适合作为状态，即定义 f[i]f[i]f[i] 表示从「访问到房间 iii 且次数为奇数」到「访问到房间 iii 且次数为偶数」所需要的天数。

请注意，这个定义包含了首次访问房间 iii 的一天，和重新回到房间 iii 的一天。

状态转移方程
由于 [j,i−1][j,i-1][j,i−1] 范围内的每个房间都需要「回访」，所以需要把这个范围内的 fff 值都加起来，再算上房间 iii 需要访问 222 次，于是得到如下状态转移方程：

f[i]=2+∑k=ji−1f[k](1)f[i] = 2 + \sum_{k=j}^{i-1} f[k] \tag{1}
f[i]=2+ 
k=j
∑
i−1
​
 f[k](1)
其中和式可以用前缀和优化，请看 前缀和原理。

定义前缀和 s[0]=0, s[i+1]=∑j=0if[i]s[0]=0,\ s[i+1]=\sum\limits_{j=0}^{i}f[i]s[0]=0, s[i+1]= 
j=0
∑
i
​
 f[i]。

于是 (1)(1)(1) 式化简为

f[i]=2+s[i]−s[j](2)f[i] = 2 + s[i] - s[j] \tag{2}
f[i]=2+s[i]−s[j](2)
对于前缀和 sss，有如下递推式

s[i+1]=s[i]+f[i](3)s[i+1] = s[i] + f[i] \tag{3}
s[i+1]=s[i]+f[i](3)
(2)(3)(2)(3)(2)(3) 联立得

s[i+1]=s[i]⋅2−s[j]+2(4)s[i+1] = s[i]\cdot 2 - s[j] + 2 \tag{4}
s[i+1]=s[i]⋅2−s[j]+2(4)
通过一番计算，我们省去了 fff 数组，(4)(4)(4) 式就是最终的状态转移方程。

答案
访问完所有房间，相当于访问完 000 号房间的天数，加上访问完 111 号房间的天数，加上访问完 222 号房间的天数，……，加上访问完 n−2n-2n−2 号房间的天数，再加上访问第 n−1n-1n−1 号房间的 111 天。

所以总共需要

f[0]+f[1]+⋯+f[n−2]+1=s[n−1]+1f[0] + f[1] + \cdots + f[n-2] + 1 = s[n-1] + 1
f[0]+f[1]+⋯+f[n−2]+1=s[n−1]+1
天。

由于我们从第 000 天开始计数，上式需要减一，所以访问完所有房间时的日期编号为

s[n−1]+1−1=s[n−1]s[n-1]+1-1 = s[n-1]
s[n−1]+1−1=s[n−1]
注：题目要求 (i+1) mod n(i+1)\bmod n(i+1)modn，这个取模其实是多余的，因为当我们首次访问到 n−1n-1n−1 号房间时，整个流程就结束了，在此之前 i<n−1i < n-1i<n−1，所以 (i+1) mod n(i+1)\bmod n(i+1)modn 其实就是 i+1i+1i+1。

答疑
问：代码中的注释 + MOD 避免算出负数 是什么意思？

答：sss 是前缀和，看上去它是个递增的序列，但是取模后，谁大谁小就不一定了，取模后 sss 就没有有序的性质了，那么在计算减法时，就可能会产生负数。为了保证计算结果非负，可以加上 MOD，这一方面不影响取模结果，另一方面保证了 MOD - s[j] 非负，从而保证计算结果非负。

 * 
 */


class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        constexpr int mod=1e9+7;
        int n=nextVisit.size();
        vector<long> s(n+1);

        for(int i=0;i<n-1;i++){
            int j=nextVisit[i];
            s[i+1]=(s[i]*2-s[j]+2+mod)%mod;
        }
        return s[n-1];
    }
};
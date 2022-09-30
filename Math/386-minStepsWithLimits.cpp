/*
You start with the integer 1 and you want to reach the integer target.

In one move, you can either:
Increment the current integer by one (i.e., x = x + 1).
Double the current integer (i.e., x = 2 * x).

You can use the increment operation any number of times, however, 
you can only use the double operation at most maxDoubles times. 
Given the two integers target and maxDoubles, 
return the minimum number of moves needed to reach target starting with 1.

Example 1:

Input: target = 5, maxDoubles = 0
Output: 4
Explanation: Keep incrementing by 1 until you reach target.

Example 2:
Input: target = 19, maxDoubles = 2
Output: 7
Explanation: Initially, x = 1
Increment 3 times so x = 4
Double once so x = 8
Increment once so x = 9
Double again so x = 18
Increment once so x = 19

Example 3:
Input: target = 10, maxDoubles = 4
Output: 4
Explanation: Initially, x = 1
Increment once so x = 2
Double once so x = 4
Increment once so x = 5
Double again so x = 10

Constraints:
1 <= target <= 10^9
0 <= maxDoubles <= 100
*/

#include<iostream>
int f(int val,int m)
{
    if(val==1)
        return 0;
    
    if(m>0&&(val&1)==0)
    {
        return f(val/2,m-1)+1;
    }
    if(m==0)
        return val-1;
    return 1+f(val-1,m);

}


int steps(int val,int m)
{
    int ans=0;
    while(val>1&&m>0)
    {
        if((val&1)==0)
        {
            val/=2;
            m-=1;
        }
        else
            val-=1;
        ans+=1;
    }
    return ans+val-1;
}

int main()
{
    std::cout<<f(10,4)<<'\n';
    std::cout<<steps(10,4);
}
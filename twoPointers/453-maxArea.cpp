
/*
Given n non-negative integers a_1, a_2, ..., a_n   where each represents a point at coordinate (i, a_i) . 
‘ n ‘ vertical lines are drawn such that the two endpoints of line i is at (i, a_i)and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
The program should return an integer which corresponds to the maximum area of water 
that can be contained (maximum area instead of maximum volume sounds weird but this is the 2D plane we are working with for simplicity).

Note: You may not slant the container. 
Input: array = [1, 5, 4, 3]
Output: 6
Explanation : 
5 and 3 are distance 2 apart. 
So the size of the base = 2. 
Height of container = min(5, 3) = 3. 
So total area = 3 * 2 = 6

Input: array = [3, 1, 2, 4, 5]
Output: 12
Explanation : 
5 and 3 are distance 4 apart. 
So the size of the base = 4. 
Height of container = min(5, 3) = 3. 
So total area = 4 * 3 = 12
*/
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
using VEC=std::vector<int>;
int maxArea(const VEC& h)
{
    int n=h.size();
    if(n==0)
        return 0;
    
    int l=0,r=n-1;
    int ans=0;
    while(l<r)
    {
        int curHeight=min(h[l],h[r]);
        ans=max(curHeight*(r-l),ans);
        if(h[l]<h[r])
            l+=1;
        else
            r-=1;
    }
    return ans;
}

int main()
{
    VEC h{3,1,2,4,5};//{1,8,6,2,5,4,8,3,7};
    std::cout<<maxArea(h);
}
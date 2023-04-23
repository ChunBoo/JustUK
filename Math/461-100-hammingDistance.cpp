#include<iostream>
#include<algorithm>
using std::cout;
class Solution {
public:
    int hammingDistance(int x, int y) {
        if(x<y)
            std::swap(x,y);
        int ans=0;
        while(x)
        {
            int tx=x&1,ty=y&1;
            if(tx!=ty)
             ans+=1;
            x>>=1;
            y>>=1;
        }
        return ans;
    }
};


int main()
{
    int x=12,y=3;
    cout<<Solution().hammingDistance(x,y);
}
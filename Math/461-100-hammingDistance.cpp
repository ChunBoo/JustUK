class Solution {
public:
    int hammingDistance(int x, int y) {
        if(x<y)
            swap(x,y);
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
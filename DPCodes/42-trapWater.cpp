class Solution {
public:
    int trap(vector<int>& height) {
        // int n=height.size();
        // if(n==0)
        //     return 0;
        // int ans=0;

        // auto begin=cbegin(height);
        // auto end=cend(height);

        // for(int i=0;i<n;++i)
        // {
        //     int l=*max_element(begin,begin+i+1);
        //     int r=*max_element(begin+i,end);
        //     ans+=min(l,r)-height[i];
        // }
        // return ans;
        //DP 
        int n=height.size();
        if(n==0)
            return 0;
        vector<int> l(n,0);
        vector<int> r(n,0);
        for(int i=0;i<n;++i)
            l[i]=i==0?height[i]:max(height[i],l[i-1]);
        for(int i=n-1;i>-1;--i)
            r[i]= i==n-1?height[i]:max(height[i],r[i+1]);
        int ans=0;
        for(int i=0;i<n;++i)
            ans+=min(l[i],r[i])-height[i];
        
        return ans;
    }
};
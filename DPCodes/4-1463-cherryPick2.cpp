class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int m=grid.size();
        const int n=grid[0].size();

        vector<vector<vector<int>>> m_(m,vector<vector<int>>(n,vector<int>(n,-1)));

        function<int(int,int,int)> dp = [&](int r,int c1,int c2){
            if(c1<0||c1>=n||c2<0||c2>=n||r<0||r>=m)
                return 0;
            int& ans=m_[r][c1][c2];
            if(ans!=-1)
                return ans;
            const int cur=grid[r][c1]+grid[r][c2]*(c1!=c2);
            for(int d1=-1;d1<=1;++d1){
                for(int d2=-1;d2<=1;++d2){
                    ans=max(ans,cur+dp(r+1,c1+d1,c2+d2));

                }
            }
            return ans;
        };
        return dp(0,0,n-1);
    }
};
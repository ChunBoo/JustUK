class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // int n=triangle.size();
        // vector<vector<int>> f(n+1,vector<int>(n+1,INT_MAX));

        // for(int r=1;r<=n;++r)
        // {
        //     for(int c=1;c<=r;++c)
        //     {
        //         f[r][c]=triangle[r-1][c-1];
        //         if(r==1&&c==1)
        //             continue;
        //         if(c==1)
        //             f[r][c]+=f[r-1][c];
        //         else if(c==r)
        //             f[r][c]+=f[r-1][c-1];
        //         else    
        //             f[r][c]+=min(f[r-1][c],f[r-1][c-1]);
        //     }

        // }
        // return *min_element(begin(f[n]),end(f[n]));

        int n=triangle.size();
        vector<vector<int>> f(2,vector<int>(n+1,INT_MAX));

        for(int r=1;r<=n;++r)
        {
            for(int c=1;c<=r;++c)
            {
                f[1][c]=triangle[r-1][c-1];
                if(r==1&&c==1)
                    continue;
                if(c==1)
                    f[1][c]+=f[0][c];
                else if(c==r)
                    f[1][c]+=f[0][c-1];
                else
                    f[1][c]+=min(f[0][c],f[0][c-1]);
            }
            std::swap(f[0],f[1]);
        }
        return *min_element(f[1].cbegin(),f[1].cend());
    }
};
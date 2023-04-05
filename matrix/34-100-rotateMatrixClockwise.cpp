class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int R=matrix.size(),C=matrix[0].size();
        //transpose
        for(int r=0;r<R;++r)
        {
            for(int c=0;c<r;++c)
            {
                int tmp=matrix[r][c];
                matrix[r][c]=matrix[c][r];
                matrix[c][r]=tmp;
            }
        }
        for(int r=0;r<R;++r)
        {
            for(int c=0,e=C-1;c<C/2;++c,--e)
            {
                int tmp=matrix[r][c];
                matrix[r][c]=matrix[r][e];
                matrix[r][e]=tmp;
            }
        }


    }
};
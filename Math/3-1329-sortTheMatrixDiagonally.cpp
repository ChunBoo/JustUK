class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int m=mat.size(), n=mat[0].size();
        vector<int> data(min(m,n));

        for(int k=1-n;k<m;k++)  //k=i-j
        {
            int leftRow=max(0,k),rightRow=min(k+n,m);
            for(int i=leftRow;i<rightRow;++i){
                data[i-leftRow]=mat[i][i-k];
            }
            sort(begin(data),begin(data)+(rightRow-leftRow));
            for(int i=leftRow;i<rightRow;++i)
                mat[i][i-k]=data[i-leftRow];
        }
        return mat;
    }
};
int m_[101][101][101];  //global variable
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        const int n=boxes.size();
        // m_=vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,0)));
        memset(m_,0,sizeof(m_));
        dfs(boxes,0,n-1,0);
        return m_[0][n-1][0];
    }
private:
    // vector<vector<vector<int>>> m_;
    int dfs(const vector<int>& boxes, int l,int r,int k)
    {
        if(l>r)
            return 0;
        if(m_[l][r][k]>0) 
            return m_[l][r][k];
        m_[l][r][k]=dfs(boxes,l,r-1,0)+(k+1)*(k+1);
        for(int i=l;i<r;++i){
            if(boxes[i]==boxes[r])
            {
                m_[l][r][k]=max(m_[l][r][k],dfs(boxes,l,i,k+1)+dfs(boxes,i+1,r-1,0));
            }
        }
        return m_[l][r][k];
    }
};
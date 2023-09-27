#include<iostream>
#include<vector>
// #include<>
using namespace std;

class Solution {
private:
    vector<vector<int>> m_;
    int score(const vector<int>& piles,int l,int r){
        if(l==r) return piles[l];
        if(m_[l][r]==INT_MIN)
            m_[l][r]=max(piles[l]-score(piles,l+1,r),
                         piles[r]-score(piles,l,r-1));
        return m_[l][r];
    }
public:
    bool stoneGame(vector<int>& piles) {
        const int n=piles.size();
        m_=vector<vector<int>>(n,vector<int>(n,INT_MIN));
        return score(piles,0,n-1);
    }
};

int main()
{
    vector<int> piles{2,7,9,4,4};
    cout<<Solution().stoneGame(piles);
}
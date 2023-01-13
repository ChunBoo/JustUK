#include<iostream>
#include<vector>
#include<numeric>

using VEC=std::vector<int>;


VEC myAccumulate(const VEC& cards)
{
    VEC ans{0};
    int s{};
    for(int i=0;i<cards.size();++i)
    {
        s+=cards[i];
        ans.push_back(s);
    }
    return ans;
}

int maxScore(const VEC& cards,int k)
{
    VEC p{myAccumulate(cards)};
    int n=cards.size();

    int s=std::accumulate(cards.begin(),cards.end(),0);
    int ans{};
    for(int i=0;i<k+1;++i)
    {
        int cur=p[i]+s-p[n-(k-i)];
        ans=std::max(ans,cur);
    }
    return ans;
}

int main()
{
    // VEC c{1,2,3,4,5,6,1};
    VEC c{96,90,41,82,39,74,64,50,30};
    int k=8;
    std::cout<<maxScore(c,k);
}

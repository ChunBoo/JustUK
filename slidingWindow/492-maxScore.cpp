#include<vector>
#include<iostream>
#include<numeric>   //for std::accumulate
using VEC=std::vector<int>;


int maxScore(const VEC& cards,int k)
{
    int n=cards.size();
    int i=n-k;
    int win=std::accumulate(cards.begin(),cards.begin()+(i),0);
    int ma=win;
    while(i<n)
    {
        win+=cards[i];
        win-=cards[i-(n-k)];
        ma=std::min(ma,win);
        i+=1;
    }
    return std::accumulate(cards.begin(),cards.end(),0)-ma;
}

int main()
{
    VEC cards{1,2,3,4,5,6,1};
    std::cout<<maxScore(cards,4);
}
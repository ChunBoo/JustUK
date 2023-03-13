#include<iostream>
#include<cmath>
#include<vector>

using std::cout;
using VEC=std::vector<int>;


class TN
{
    public:
        int m_v{};
        TN* left{};
        TN* right{};
        TN(int v,TN* l=nullptr, TN* r=nullptr):m_v{v},left{l},right{r}{};
};

void dfoo(const TN* root,const TN* prev,int &ans)
{
    if(!root)
        return ;
    dfoo(root->left,prev,ans);
    if(prev)
    {
        ans=std::min(ans,root->m_v-prev->m_v);
    }
    prev=root;
    dfoo(root->right,prev,ans);
}

int minDiff(const TN* root)
{
    TN* prev=nullptr;
    int ans=INT_MAX;
    dfoo(root,prev,ans);
    return ans;
}
void inorderTra(const TN* root,VEC& nums)
{
    if(!root)
        return ;
    inorderTra(root->left,nums);
    nums.push_back(root->m_v);
    inorderTra(root->right,nums);
}

int minDiff2(const TN* root)
{
    // TN* prev=nullptr;
    int ans=INT_MAX;
    // dfoo(root,prev,ans);
    VEC nums{};
    inorderTra(root,nums);
    int n=nums.size();
    for(int i=1;i<n;++i)
    {
        ans=std::min(ans,nums[i]-nums[i-1]);
    }
    return ans;
}
int main()
{
    TN *root=new TN(10);
    TN *one=new TN(1);
    TN *two=new TN(12);
 

    root->left=one;
    // two->right=one;
    root->right=two;
    std::cout<<minDiff2(root);
}

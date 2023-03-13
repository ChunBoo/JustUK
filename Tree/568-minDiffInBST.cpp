#include<iostream>
#include<cmath>
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

int main()
{
    TN *root=new TN(10);
    TN *one=new TN(1);
    TN *two=new TN(12);
 

    root->left=one;
    // two->right=one;
    root->right=two;
    std::cout<<minDiff(root);
}

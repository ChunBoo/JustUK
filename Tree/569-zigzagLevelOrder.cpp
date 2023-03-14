#include<vector>
#include<iostream>
#include<deque>
#include<algorithm>
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
using Q=std::deque<const TN*>;
using MATRIX=std::vector<VEC>;

MATRIX zigzagOrderByLevel(const TN* root)
{
    MATRIX ans{};
    if(!root)
        return ans;
    Q q{};
    q.push_back(root);
    while(!q.empty())
    {
        int n=q.size();
        VEC tmp{};
        for(int i=0;i<n;++i)
        {
            const TN *cur=q.front();
            q.pop_front();
            tmp.push_back(cur->m_v);
            if(cur->left)
                q.push_back(cur->left);
            if(cur->right)
                q.push_back(cur->right);
        }
        if(ans.size()&1)
        {
            std::reverse(tmp.begin(),tmp.end());
            ans.push_back(tmp);
        }
        else   //this step can not be skipped
            ans.push_back(tmp);
    }
    return ans;
}

int main()
{
        TN *root=new TN(10);
    TN *one=new TN(1);
    TN *two=new TN(2);
    TN *two2=new TN(3);
    TN *third=new TN(4);
    TN *four=new TN(5);

    root->left=two;
    root->right=two2;
    two->left=third;
    two->right=four;
    two2->left=four;
    two2->right=third;

    MATRIX res=zigzagOrderByLevel(root);
    for(auto &_:res)
    {
        cout<<'[';
        for(auto &v:_)
        {
            cout<<v<<',';
        }
        cout<<']'<<'\n';
    }
}

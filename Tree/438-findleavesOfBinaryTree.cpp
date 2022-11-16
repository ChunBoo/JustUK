#include<iostream>
#include<map>
#include<vector>
using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;
using DATA=std::map<int,VEC>;

class TreeNode
{
    private:
        int m_val{};
        TreeNode* left{};
        TreeNode* right{};
    public:
        TreeNode(int v, TreeNode* l=nullptr, TreeNode* r=nullptr):
                m_val{v},left{l},right{r}{}
        
        void setLeft( TreeNode* l){left=l;}
        TreeNode* getLeft() const {return left;}
        TreeNode* getRight() const {return right;}
        void setRight( TreeNode* r){right=r;}

        int getVal() const {return m_val;}
};

int f(const TreeNode* root, DATA& data)
{
    if(!root)
        return 0;
    int l=f(root->getLeft(),data);
    int r=f(root->getRight(),data);
    int d=std::max(l,r)+1;
    int val=root->getVal();
    data[d].push_back(val);
    return d;
}

DATA findAllLeaves(const TreeNode* root)
{
    DATA data{};
    if(!root)
        return data;
    f(root, data);
    return data;
}


int main()
{
    TreeNode* root= new TreeNode(0);
    TreeNode* one= new TreeNode(1);
    TreeNode* two=new TreeNode(2);
    TreeNode* three=new TreeNode(3);
    TreeNode* four=new TreeNode(4);
    root->setLeft(one);
    root->setRight(three);
    one->setLeft(two);
    one->setRight(four);
    DATA res=findAllLeaves(root);
    DATA::iterator iter=res.begin();
    for(auto &[k,v]:res)
    {
        std::cout<<"[";
        for(auto &d:v)
        {
            std::cout<<d<<',';
        }
        std::cout<<']'<<'\n';
    }
}
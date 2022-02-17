#ifndef N_ARY_TREE
#define N_ARY_TREE
#include<vector>
class NNode
{
    public:
        int m_val;
        std::vector<NNode*> m_children{};
        NNode(int v):m_val{v}{}
        void addChild(NNode* node){m_children.push_back(node);}
};

#endif
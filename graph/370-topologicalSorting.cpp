


#include<map>
#include<queue>
#include<vector>
#include<iostream>
class Node;
using VEC=std::vector<Node>;
using MATRIX=std::vector<VEC>;

class Node
{
    private:
        int m_inDegree{0};
        std::vector<Node> m_outNodes{};
    public:
        Node()=default;
        virtual ~Node(){}

        int getInDegree() const{return m_inDegree;}
        void setInDegree(int v){m_inDegree=v;}
        void insertOutNode(Node& n){m_outNodes.push_back(n);}
        VEC getOutNodes(){return m_outNodes;}
};
using VEC=std::vector<Node>;
using MATRIX=std::vector<VEC>;

class Solution
{
    public:
        bool canComplete(MATRIX& course)
        {
            int totalDep{0};
            std::map<Node,Node> G{};

            for(auto &r:course)
            {
                G[r[0]].setInDegree(r[0].getInDegree()+1);
                G[r[1]].insertOutNode(r[0]);
                totalDep+=1;
            }
            std::deque<Node> q{};

            for(auto &[a,node]:G)
            {
                if(node.getInDegree()==0)
                    q.push_back(a);
            }
            
            int r{0};
            while(!q.empty())
            {
                Node cur=q.front();q.pop_front();
                VEC allOutNodes=cur.getOutNodes();
                for(auto &n:allOutNodes)
                {
                    int curInDegree=n.getInDegree();
                    G[n].setInDegree(curInDegree-1);
                    r+=1;
                    if(n.getInDegree()==0)
                        q.push_back(n);
                }
            }
            return r==totalDep; 
        }
};

int main()
{
    MATRIX courses{{Node(1),Node(0)},{Node(2),Node(1)}};
    Solution s;
    std::cout<<s.canComplete(courses);

}
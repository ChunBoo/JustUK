//BFS: breadth first search

#include<iostream>
#include<vector>
#include<queue>
#include<set>
class Solution
{
    public:
// std::vector<int> nums{2,0,3,1,3,4};
        bool dfsJumpGame(const std::vector<int>& nums,int t,int s,std::set<int>& nb)
        {

            int sz=nums.size();
            if(sz==0)
                return false;
            if(nums[s]==t)
                return true;
            std::vector<int> directVec{-1,1};
            for(auto i:directVec)
            {
                int next=nums[s]*i+s;
                std::set<int>::iterator tempIt;
                tempIt=nb.find(next);
                if(tempIt==nb.end()&&next<sz&&next>=0)
                {
                    nb.insert(next);
                
                    if(dfsJumpGame(nums,t,next,nb))
                        return true;
                    nb.erase(next);
                }
            }
            return false;
        }

        bool bfsJumpGame(const std::vector<int>& nums,int t,int s)
        {
            std::set<int> gSet;
            int sz=nums.size();
            if(sz==0)
                return false;
            if(nums[s]==t)
                return true;
            std::queue<int> q;
            std::vector<int> directionVec{-1,1};
            q.push(s);
            while(q.size()>0)
            {
                int now=q.front(); 
                std::set<int>::iterator tmpIt;
                q.pop();
                
                if(nums[now]==t)
                    return true;
 
                for(auto i:directionVec)
                {
                    int nextPos=now+i*nums[now];
                    tmpIt=gSet.find(nextPos);
                    if(tmpIt==gSet.end() && nextPos>=0 &&nextPos<sz)
                    {
                        q.push(nextPos);
                        gSet.insert(nextPos);
                    }
                }
            }
            return false;
        }
};


int main()
{
    Solution s;
    std::set<int> nb;
    std::vector<int> nums{2,0,3,1,3,4};
    int target=0,startPos=3;

    // int isCanFind=s.bfsJumpGame(nums,target,startPos);
    int isCanFind=s.dfsJumpGame(nums,target,startPos,nb);

    std::cout<<"Can arrive the destination: "<<target<<" from pos: "<<startPos<<" is "<<isCanFind<<'\n';

    return 0;
}
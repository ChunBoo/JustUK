//given a array, and the start/end index,to return the sum of this range 

#include<vector>
#include<iostream>
#include<cmath>
using DT=std::vector<int>;
class Solution
{
    private:
        int m_group{};
        DT m_blocks{};
        DT m_nums{};
    public:    
        Solution(const DT& nums)
        {
            int len=nums.size();
            m_nums=nums;
            m_group=static_cast<int>(std::sqrt(len));
            m_blocks=DT(m_group,0);
            for(int i=0;i<len;++i)
                m_blocks[i/m_group]+=nums[i];
        }
        void updateBlock(int idx,int val)
        {
            m_blocks[idx/m_group]+=(val-m_nums[idx]);
            m_nums[idx]=val;
        }
        int rangeOfSum(int start,int end)
        {
            
            if((end<start))
                return 0;   

            int ans{0};
            int p=start;
            while(p<=end)
            {
                if((p%m_group==0)&&((p+m_group)<end))
                {
                    ans+=m_blocks[p/m_group];
                    p+=m_group;
                }
                else
                {
                    ans+=m_nums[p];
                    p+=1;
                }
            }
            return ans;
        }
};

int main()
{
    DT nums{1,2,3,4,5,6,7,8,9};
    Solution s{nums};
    s.updateBlock(1,3);
    int res=s.rangeOfSum(1,3);
    std::cout<<res;
    return 0;
}
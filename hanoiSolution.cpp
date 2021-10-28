#include<iostream>
#include <cassert>
#include <string>
class Solution
{   
    private:
        int m_disks;

    public:
        Solution(int disks):m_disks{disks}{};
        void hanoiSolution(int disks,const std::string& src,const std::string& dest,const std::string& tmp)
        {
            assert(disks>0);
            if(disks==1)
            {
                std::cout<< "move the disk "<<disks<<" from "<< src <<" to "<< dest<<" using "<<tmp<<" as the tempory tower.\n";
                return ;
            }
            hanoiSolution(disks-1,src,tmp,dest);
            std::cout<<"Move the disks:"<< disks<<"from "<<src <<" to "<<dest<<".\n";
            hanoiSolution(disks-1,tmp,dest,src);
            // std::cout<<
        }
};

int main()
{
    Solution s(3);
    s.hanoiSolution(4,"source","destination","temp");

    return 0;
}
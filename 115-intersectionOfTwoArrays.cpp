// get the intersection of two arrays
//[1,2,3,3,4,5]&[1,2,3,4,5]==[3,4,5]

#include<vector>
#include<iostream>
#include<algorithm>


void getIntersectionOfTwoArrays(std::vector<int>& vA, std::vector<int>& vB,std::vector<int>& res)
{
    if(vA.empty()||vB.empty())
        return ;
    
    std::sort(vA.begin(),vA.end());
    std::sort(vB.begin(),vB.end());

    int szA=vA.size();
    int szB=vB.size();

    int iA=0,iB=0;

    while(iA<szA&&iB<szB)
    {
        if(vA[iA]==vB[iB])
        {
            res.push_back(vA[iA]);
            iA+=1;
            iB+=1;
        }
        else if (vA[iA]<vB[iB])
        {
            iA+=1;
        }
        else
           iB+=1;
    }
}


int main()
{
    std::vector<int> a{1,2,3,3,4,5};
    std::vector<int> b{3,3,4,5};
    std::vector<int> res{};

    getIntersectionOfTwoArrays(a,b,res);
    std::cout<<"The result is:";
    for(auto i:res)
    {
        std::cout<<i<<'-';
    }

    std::cout<<'\n';

    return 0;
}
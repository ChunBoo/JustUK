#include<iostream>
#include<vector>
#include<cmath>
using DT=std::vector<std::vector<int>>;

DT getIntervalsIntersection(DT& A,DT& B)
{
   DT ans{};
   size_t la=A.size(), lb=B.size();
   size_t i=0,j=0;
   while(i<la&&j<lb)
   {
       int start=std::max(A[i][0],B[j][0]);
       int end=std::min(A[i][1],B[j][1]);
       if(start<=end)
       {
        //    std::vector<int> tmp{start,end};
        //    ans.push_back(tmp);
           ans.push_back({start,end});
       }
       if(A[i][1]<B[j][1])
         i+=1;
       else
         j+=1;
   }
   return ans;
}

int main()
{
    DT A={{1,3},{5,6},{7,9}};
    DT B={{1,2},{3,7}};
    DT res=getIntervalsIntersection(A,B);
    for(auto i:res)
    {
        for(auto j:i)
            std::cout<<j<<',';
        std::cout<<'\n';
    }
    return 0;
}
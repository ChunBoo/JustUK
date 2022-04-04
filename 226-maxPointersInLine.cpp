#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using DT=std::vector<std::vector<int>>;
int getMaxPointers(DT& cords)
{
    if(cords.size()==2)
        return 2;
    std::map<float,int> m{};
    int ans=0;
    for(int i=0;i<cords.size();++i)
    {
        int x1=cords[i][0],y1=cords[i][1];
        for(int j=0;j<i;++j)
        {
            int x2=cords[j][0],y2=cords[j][1];
            if(x1!=x2)
            {
                float s=static_cast<float>(y2-y1)/(x2-x1);
                m[s]+=1;
            }
        }
    }
    for(auto i:m)
    {
        if(i.second>ans)
            ans=i.second;
    }
    return ans+1;
}

int main()  //y=x+1,
{
    DT c{{1,2},{2,3},{3,5},{1,3}};
    std::cout<<getMaxPointers(c);
    return 0;
}
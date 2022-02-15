#include<iostream>
#include<vector>
#include<algorithm>   //for std::find
#include<set>
using std::vector;
using std::set;
bool isValidSDK(vector<vector<int>>& nums)
{
    vector<set<int>> row(9,set<int>);
    vector<int> col(9,0);
    vector<vector<int>> box(3,vector<int>(3,0));
    vector<int>::iterator rItor;
    vector<int>::iterator cItor;
    vector<vector<int>>::iterator boxItor;

    for(int r=0;r<9;++r)
    {
        for(int c=0;c<9;++c)
        {
            int curVal=nums[r][c];
            if(curVal>9||curVal<0)
                return false;
            if(std::find(row.begin(),row.end(),curVal)!=row.end())
                return false;
            if(std::find(col.begin(),col.end(),curVal)!=col.end())
                return false;
            if(std::find(box.begin(),box.end(),curVal)!=box.end())
                return false;
            row[r]
        }
    }
}
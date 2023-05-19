#include<iostream>
#include<vector>
#include<algorithm>

using VEC=std::vector<int>;
using std::cout;
using MATRIX=std::vector<VEC>;

class Solution {
public:

    static bool cmp(VEC& a, VEC& b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]>b[0];
    }
    MATRIX reconstructQueue(MATRIX& people) {
        std::sort(people.begin(),people.end(),cmp);
        MATRIX ans{};
        int n=people.size();
        for(int i=0;i<n;++i)
        {
            int pos=people[i][1];
            ans.insert(ans.begin()+pos, people[i]);
        }
        return ans;
    }
};


int main()
{
   MATRIX people{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
   MATRIX res=Solution().reconstructQueue(people);
   for(auto &v:res)
   {
        cout<<'[';
        for(auto &d:v)
            cout<<d<<',';
        cout<<']';
   }
}
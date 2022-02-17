#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>
bool isCanSplitSet(std::vector<int>& s)
{
    std::sort(s.begin(),s.end());  //why needs this step?? for what?
    int c=0;

    int sum=std::accumulate(s.begin(),s.end(),0);
    int sz=s.size();
    for(int i=0;i<sz;++i)
    {
        c+=s[i];
        if((c*2==sum) && (s[i]<s[i+1]))
            return true;
        if(c*2>sum)
            return false;
    }
    return false;
}

int main()
{
    std::vector<int> nums{4,6,9};
    bool res=isCanSplitSet(nums);
    std::cout<<res<<'\n';
    return 0;
}
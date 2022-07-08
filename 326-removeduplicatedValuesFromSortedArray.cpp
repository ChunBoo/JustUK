#include<iostream>
#include<vector>
#include<set>

using DT=std::vector<int>;

int removeDuplicatedValues(DT& a)
{
    if(a.empty())
        return 0;
    std::set<int> s{};  //std::set is ordered 
    //std::set is an associative container that contains a sorted set of unique objects of type Key
    for(auto &i:a)
        s.insert(i);

    //std::set no [] operator
    std::set<int>::iterator iter=s.begin();
    int idx=0;
    for(;iter!=s.end()&&idx<a.size();++iter,++idx)
    {
        a[idx]=*iter;
    }
    return idx;
}

int removeDuplicatedValuesWithoutSet(DT& a)
{
    if(a.empty())
        return 0;
    int x=1;
    for(int i=1;i<a.size();++i)
    {
        if(a[i]!=a[i-1])
        {
            a[x]=a[i];
            ++x;
        }
    }
    return x;
}


int main()
{
    DT arr{1,2,2,3,4,4,5,6};
    int res=removeDuplicatedValues(arr);
    std::cout<<res<<'\n';
    for(auto i:arr)
        std::cout<<i<<',';
    int res2=removeDuplicatedValuesWithoutSet(arr);
    std::cout<<"\n"<<res2<<'\n';
    for(auto i:arr)
        std::cout<<i<<',';
    return 0;
}
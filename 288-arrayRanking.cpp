#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
using DT=std::vector<int>;
using std::set;

struct Comparator
{
    Comparator(bool g) : m_g(g){}
     bool operator()(int i1, int i2) const
    {
        if(m_g)
        {
            return i1>i2;
        }
        return i1<i2;
    }
        bool m_g;
};

class CComparator
{
    private:
        bool m_g;
    public:
        CComparator(bool isLarger):m_g{isLarger}{}
        bool operator()(int x,int y) const
        {
            if(m_g)
                return x>y;
            return x<y;
        }
};
// int main(int argc, char** argv)
// {
//     Comparator l(false);
//     set<int,Comparator> a(l);
//     a.insert(1);
//     a.insert(2);
//     a.insert(3);
//     // Comparator g(true);
//     // set<int,Comparator> b(g);
//     // copy(a.begin(), a.end(), inserter(b, b.begin()));
//     // a = b;
//     for(auto i:a)
//         std::cout<<i<<',';
//     std::cout<<"\nset b:\n";
//     // for(auto i:b)
//     //     std::cout<<i<<',';
//     return 0;
// }
DT arrayRanking( DT& nums)
{
    std::vector<int> ans{};
    std::map<int,int> m{};
    CComparator larger(true);
    std::set<int,CComparator> s(larger);

    for(int i:nums)
    {
        s.insert(i);
    }
    DT temp{};
    for(auto &i:s)
        temp.push_back(i);
    // std::set<int>::iterator itor=s.end();
    // for(;itor!=s.begin();--itor)
    //     temp.push_back(*itor);

    for(int i=0;i<s.size();++i)
    {
        m[temp[i]]=i;
    }

    for(auto i:nums)
    {
        ans.push_back(m[i]);
    }
    return ans;
}


int main()
{
    DT nums={60,100,100,90,50};
    DT ret=arrayRanking(nums);
    for(auto &i:ret)
        std::cout<<i<<',';
    return 0;
}
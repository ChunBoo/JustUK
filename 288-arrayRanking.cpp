#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<vector>

using DT=std::vector<int>;

class CCompare
{
    private:
        int m_g;
    public:
        CCompare(int g):m_g{g}{}
        bool operator()(int a,int b) const
        {
            if(m_g)
                return a>b;
            return a<b;
        }
};

DT arrayRankingWithoutNewVector(const DT& nums)
{
    CCompare larger(true);

    std::set<int,CCompare> s(larger);  //create a set to filter nums with descending order
    for(auto i:nums)
        s.insert(i);

    // DT temp{};
    // for(auto &i:s)
    //     temp.push_back(i);

    std::map<int,int> m{};
    std::set<int>::iterator iter{s.begin()};

    for(int idx=0;iter!=s.end();++iter,++idx)
        m[*iter]=idx;
    DT ans{};
    // for(auto &i:nums)
        // ans.push_back(m[i]);
    for(int i=0;i<nums.size();++i)
    {
        ans.push_back(m[nums[i]]);
    }
    return ans;
}   
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
            {
                return x>y;
            }
            else
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
DT arrayRanking( DT nums)
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
<<<<<<< HEAD
    DT nums{50,60,90,100,100};
    DT res=arrayRanking(nums);
    for(auto &v:res)
        std::cout<<v<<',';
=======
    DT nums={60,100,100,90,50};
    DT ret=arrayRanking(nums);
    for(auto &i:ret)
        std::cout<<i<<',';
>>>>>>> 3dd4373daa99570a7454d15769850eb038463612
    return 0;
}
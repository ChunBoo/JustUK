#include<iostream>
#include<vector>
#include<set>
#include<map>
using VEC=std::vector<int>;
using S=std::set<int>;
using MAP=std::map<int,int>;


VEC twoOutOfThree1(const VEC& n1, const VEC& n2, const VEC& n3)
{
    S s1{n1.begin(),n1.end()};
    S s2{n2.begin(),n2.end()};
    S s3{n3.begin(),n3.end()};

    S ans{};
    for(auto iter=s1.begin();iter!=s1.end();++iter)
    {
        if(s2.find(*iter)!=s2.end() || s3.find(*iter)!=s3.end())
            ans.insert(*iter);
    }
    for(auto iter=s2.begin();iter!=s2.end();++iter)
        if(s3.find(*iter)!=s3.end())
            ans.insert(*iter);
    return VEC(ans.begin(),ans.end());
}
void myCounter(const VEC& n,MAP& d)
{
    for(auto &v:n)
        d[v]+=1;
}
VEC twoOutOfThree2(const VEC& n1, const VEC& n2, const VEC& n3)
{
    MAP d{};
    S s1{n1.begin(),n1.end()};
    S s2{n2.begin(),n2.end()};
    S s3{n3.begin(),n3.end()};
    VEC v1{s1.begin(),s1.end()};
    VEC v2{s2.begin(),s2.end()};
    VEC v3{s3.begin(),s3.end()};
    // VEC v1(s1.size()),v2(s2.size()),v3(s3.size());  //if call std::copy, we should set the size of vector firstly
    // std::copy(s1.begin(),s1.end(),v1.begin());
    // std::copy(s2.begin(),s2.end(),v2.begin());
    // std::copy(s3.begin(),s3.end(),v3.begin());
    myCounter(v1,d);
    myCounter(v2,d);
    myCounter(v3,d);
    VEC ans{};
    for(auto &[k,v]:d)
    {
        if(v>1)
            ans.push_back(k);
    }
    return ans;
}

int main()
{
    VEC v1={1,1,3,2};
    VEC v2{2,3};
    VEC v3{3};

    VEC res=twoOutOfThree1(v1,v2,v3);
    VEC res2=twoOutOfThree2(v1,v2,v3);
    for(auto &v:res2)
        std::cout<<v<<',';
}
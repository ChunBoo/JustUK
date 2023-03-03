#include<string>
#include<iostream>
#include<map>
#include<set>
#include<vector>
using STR=std::string;
using MAP=std::map<STR,int>;
using SET=std::set<char>;
using VEC=std::vector<STR>;
using std::cout;
STR str(const STR& s)
{
    SET seen{};
    STR tmp{""};
    for(auto &c:s)
        seen.insert(c);
    for(auto &cc:seen)
        tmp+=cc;
    return tmp;
}

int similarPairs(const VEC& words)
{
    MAP C{};
    int ans=0;
    for(auto &w:words)
    {
        STR t{str(w)};
        ans+=C[t];
        C[t]+=1;
    }
    return ans;
}

int main()
{
    VEC words{"aabb","ab","abc","bcaaa"};
    cout<<similarPairs(words);
}
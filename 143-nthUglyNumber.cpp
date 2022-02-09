// #include<heap>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
int getNthUglyNumber(int n)
{
    std::vector<int> min{2,3,5};

    std::vector<int> primerNumber{2,3,5};
    std::set<int> s{1};
    int cur=0;
    for(int i=1;i<n;++i)
    {    std::make_heap(min.begin(),min.end(),std::greater<int>());
        cur=min.front();
        std::pop_heap(min.begin(),min.end(),std::greater<int>());
        min.pop_back();
        for(auto v:primerNumber)
        {
            int newValue=cur*v;
            if(s.find(newValue)==s.end())
            {
                s.insert(newValue);
                min.push_back(newValue);
                std::push_heap(min.begin(),min.end(),std::greater<int>());
            }
        }  
    }
    return cur;
}

int main()
{
    int res=getNthUglyNumber(7);
    std::cout<<res<<'\n';
    return 0;
}
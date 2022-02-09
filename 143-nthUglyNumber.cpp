// #include<heap>
#include<algorithm>  //std::make_heap,std::pop_heap,std::push_heap
#include<iostream>
#include<vector>
#include<set>  // for std::set()
bool isUglyNumber(int n)
{
    // if(n<1)
    //     return false;
    if(n==1)
        return true;
    std::vector<int> val{2,3,5};
    for(auto i: val)
    {
        while(n%i==0)   //this step is important !!
        {
            n/=i;
        }
    }

    return n==1;   //if n==1 then it is a ugly number,otherwise it is not.
}
int NthUglyNumber(int n)
{
    int ans=1;
    while(true)
    {
 
        if(isUglyNumber(ans))
        {
            n-=1;
            if(n==0)
                return ans;
        }       
        ans+=1;
    }
}


int getNthUglyNumber(int n)
{
    std::set<int> s{2,3,5};
    std::vector<int> factors{2,3,5};
    std::vector<int> temp{2,3,5};
    // temp.push_back(1);
    std::make_heap(temp.begin(),temp.end(),std::greater<int>());

    int ans=0;
    while(n>1)
    {
        int cur=temp.front();
        ans=cur;
        std::pop_heap(temp.begin(),temp.end(),std::greater<int>());
        temp.pop_back();
        for(auto v:factors)
        {
            int newValue=v*cur;
            if(s.find(newValue)==s.end())
            {
                s.insert(newValue);
                temp.push_back(newValue);
                std::push_heap(temp.begin(),temp.end(),std::greater<int>());
            }
        }
        n-=1;
    }
    return ans;
}

int main()
{
    int res=getNthUglyNumber(7);
    // int res=NthUglyNumber(7);
    std::cout<<res<<'\n';
    return 0;
}
#include<iostream>
#include<vector>
int getIndexForInsertedNumberInASortedList(std::vector<int>& list,int T)
{
    if(list.empty())
        return 0;
    int sz=list.size();
    int L=0,R=sz-1;

    while(L<=R)
    {
        int mid=(L+R)/2;
        if(T<list[mid])
            R=mid-1;
        else
            L=mid+1;
    }
    return L;
}

int main()
{
    std::vector<int> list{1,1,2,3,4,5};
    int res=getIndexForInsertedNumberInASortedList(list,1);
    std::cout<<res;
    return 0;
}
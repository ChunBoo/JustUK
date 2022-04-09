//given a list of number, flip it as 0 finally, likes 10010, 
//flip first time is:01101,
//flip second time is:00010,
//flip third time is:00001,
//flip fourth time is:00000,
//solution: take each digit and current flip count, if count is even, and current digit is 1,then should add the count 
// if count is odd and current digit is 0,we should also add the count
#include<vector>
#include<iostream>

int flip2zero(const std::vector<int>& nums)
{
    int count=0;
    for(auto v:nums)
    {
        if((v==1)&&((count&1)==0))//operator of == is higher than &
            count+=1;
        if((v==0)&&((count&1)==1))
            count+=1;
    }
    return count;
}

int main()
{
    std::vector<int> l{1,0,0,1,0};
    std::cout<<flip2zero(l);
    return 0;
}
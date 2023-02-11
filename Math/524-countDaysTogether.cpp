#include<iostream>
#include<vector>
// #include<algorithm>
#include<numeric>  //for std::accumulate
#include<string>

using VEC=std::vector<int>;
using STR=std::string;
using std::cout;

int fDays(const STR& d)
{
    VEC daysPerMonth{0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mon=std::stoi(d.substr(0,2));
    int date=std::stoi(d.substr(3,2));
    int ans= std::accumulate(daysPerMonth.begin(),daysPerMonth.begin()+mon+1,0)+date;
    return ans;
}

int countDaysTogether(const STR& arrA,const STR& leaveA, const STR& arrB, const STR& leaveB)
{
    if((fDays(arrB)>fDays(leaveA))||(fDays(arrA)>fDays(leaveB)))
        return 0;
    
    return std::abs(std::min(fDays(leaveA),fDays(leaveB))-std::max(fDays(arrA),fDays(arrB)))+1;
}

int main()
{
    STR arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19";
    cout<<countDaysTogether(arriveAlice,leaveAlice,arriveBob,leaveBob);
}
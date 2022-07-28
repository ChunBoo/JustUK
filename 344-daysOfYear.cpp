#include<vector>
#include<iostream>
#include<string>
#include<numeric>
using STR=std::string;
using VEC=std::vector<int>;

int daysOfYear(const STR& date)
{
    // STR date=ddate;
    int year=std::atoi(date.substr(0,4).data());
    int month=std::atoi(date.substr(5,2).data());
    int _date=std::atoi(date.substr(8).data());

    VEC daysList{31,28,31,30,31,30,31,31,30,31,30,31};

    bool isLeapYear= (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))?true:false;

    if(isLeapYear)
        daysList[1]+=1;
    int ans=0;
    for(int i=0;i<month-1;++i)
        ans+=daysList[i];

    return ans+_date;
}


int main()
{
    // date="2004-03-01"
    STR date="2003-03-01";
    std::cout<<daysOfYear(date);
    return 0;
}
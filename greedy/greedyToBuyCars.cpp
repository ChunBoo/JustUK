//greedy algorithm to buy cars
//given the budget and each cars price,calculate the most numbers of cars which can be bought
#include<iostream>
#include<vector>
#include<algorithm>
int boughtCars(int budget,std::vector<int> prices)
{
    std::sort(prices.begin(),prices.end());
    int ans=0;
    for(auto car: prices)
    {
        if(budget>=car)
        {
            ans+=1;
            budget-=car;
        }
    }
    return ans;
}


int main()
{
    std::vector<int> prices{10,5,30,70,35,4};
    int budget=50;
    int carsCount=boughtCars(budget,prices);
    std::cout<<"With "<<budget<<" we can buy: "<<carsCount<<" cars.\n";
    return 0;
}
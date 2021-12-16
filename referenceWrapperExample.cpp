//examples of std::reference_wrapper


#include<functional>
#include<vector>
#include<iostream>
#include<list>
#include<random>
#include<numeric>
#include<algorithm>

int main()
{
    std::list<int> l(10);
    std::iota(l.begin(),l.end(),-4);
    std::vector<std::reference_wrapper<int>> v(l.begin(),l.end());

    std::shuffle(v.begin(),v.end(),std::mt19937{std::random_device{}()});

    std::cout<<"The contents in list: ";
    for(auto i:l)
        std::cout<<i<<' ';

    std::cout<<"\nThe contents in vector: \n";

    for(auto i:v)
        std::cout<<i<<' ';

    //double the element in v
    for(auto& i:l)
    {
        i*=2;
    }

    std::cout<<"\nThe contents in vector after changing: \n";
    for(auto i:v)
        std::cout<<i<<" ";
    
    return 0;
}
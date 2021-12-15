// if a given IP-V4  string is valid or not
#include<string>
#include<iostream>
#include<vector>


bool isValidIPAddress(std::string& address)
{
    if(address.size()<4)
        return false;

    std::vector<std::string> subAddress{};
    std::string dot{"."};
    std::size_t found=address.find_first_of(dot);
    std::size_t lastPos=0;
    while(found!=std::string::npos)
    {
        subAddress.push_back(address.substr(lastPos,found));
        lastPos=found+1;
        found=address.find_first_of(dot,lastPos+1);
    }
    for(auto i:subAddress)
    {
        std::cout<<i<<'\n';
    }
    return false;
}

int main()
{
    std::string add{"192.168.1.1"};
    isValidIPAddress(add);
    return 0;
}
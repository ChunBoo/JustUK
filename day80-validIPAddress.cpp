// if a given IP-V4  string is valid or not
#include<string>
#include<iostream>
#include<vector>
#include<sstream>

// 判断字符串是不是数字
bool isNum(std::string& str)
{
    std::stringstream sin(str);
    double d;
    char c;
    if(!(sin >> d))
        return false;
    if (sin >> c)
        return false;
    return true;
}
bool isValidIPAddress(std::string& address)
{
    if(address.size()<4)
        return false;

    std::vector<std::string> subAddress{};
    std::string dot{"."};
    std::size_t found=address.find(".");
    std::size_t lastPos=0;
    while(found!=std::string::npos&&subAddress.size()<4)
    {
        subAddress.push_back(address.substr(lastPos,found-lastPos));
        lastPos=found+1;
        found=address.find(".",lastPos);
    }
    subAddress.push_back(address.substr(lastPos,found));
    for(auto i:subAddress)
    {
        if(!isNum(i))
            return false;
        int tempVal=std::stoi(i);
        std::cout<<"i="<<i<<",tempVal="<<tempVal<<'\n';
        if(tempVal<0||tempVal>255)
            return false;
        if(i!=std::to_string(tempVal))
            return false;
    }
    return true;
}

int main()
{
    std::string add{"192.168.1.a"};
    bool ret=isValidIPAddress(add);
    std::cout<<add<<" is valid IP? "<<ret<<"\n";
    return 0;
}
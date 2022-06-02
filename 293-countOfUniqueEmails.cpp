#include<set>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using RDT=std::vector<std::string>;

std::vector<std::string> split(std::string str, char del)
{
    RDT ans{};
    std::string temp{};
    for(auto &c:str)
    {
        if(c!=del)
            temp+=c;
        else  //c==del now
        {
            ans.push_back(temp);
            temp="";
        }
    }   
    if(!temp.empty())
        ans.push_back(temp);
    return ans;
}

std::string getSimpleEmail(const std::string& email)
{
    std::string name=split(email,'@')[0],domain=split(email,'@')[1];
    std::string _name=split(name,'+')[0];
    while(_name.find(".")!=std::string::npos) //we should use this while-loop for removing all of the delimiter
        _name.replace(_name.find("."),1,"");
    return _name+"@"+domain;
}

int countOfUniqueEmails(const std::vector<std::string>& emails)
{
    std::set<std::string> d{};
    for(auto &i:emails)
        d.insert(getSimpleEmail(i));
    return d.size();
}

int main() 
{

    std::vector<std::string> emails{"ab.c+d@ms.com","abc+dd@ms.com"};
    std::cout<<"\n"<<countOfUniqueEmails(emails);

	// std::string str = "a_b_c"; // string to be split
	// char del = '_'; // delimiter around which string is to be split

	// std::vector<std::string> res=split(str, del);
	// for(auto &i:res)
    //     std::cout<<i<<',';
	return 0;
}


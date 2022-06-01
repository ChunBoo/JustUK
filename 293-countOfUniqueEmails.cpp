#include<set>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

std::vector<std::string> split(std::string str, char del){
	std::string temp = "";
    std::vector<std::string> ans{};
	for(int i=0; i<(int)str.size(); i++){
		if(str[i] != del)
        {
			temp += str[i];
		}
		else
        {
			// cout << temp << " ";
            ans.push_back(temp);
			temp = "";
		}
	}
    if(!temp.empty())
        ans.push_back(temp);
	return ans;
}

std::string getSimpleEmail(const std::string& email)
{
    std::string name=split(email,'@')[0];
    std::string domain=split(email,'@')[1];
    std::string _name=split(name,'+')[0];
    //remove the dot
    while(_name.find(".")!=std::string::npos)
        _name.replace(_name.find('.'),1,"");
    // std::cout<<"test:_name="<<_name;
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

    std::vector<std::string> emails{"ab.c+d@ms.com","abcdd@ms.com"};
    std::cout<<"\n"<<countOfUniqueEmails(emails);

	// std::string str = "a_b_c"; // string to be split
	// char del = '_'; // delimiter around which string is to be split

	// std::vector<std::string> res=split(str, del);
	// for(auto &i:res)
    //     std::cout<<i<<',';
	return 0;
}


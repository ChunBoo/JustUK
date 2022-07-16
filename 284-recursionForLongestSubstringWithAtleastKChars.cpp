#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include <bits/stdc++.h>
#include<vector>
// using namespace std;

void tokenize(std::string& s, const std::string& token,std::vector<std::string>& vec)
{
	int start = 0;
	int end = s.find(del);
	while (end != -1) 
    {
		// std::cout << s.substr(start, end - start) << '\n';
        vec.push_back(s.substr(start,end-start));
		start = end + del.size();
		end = s.find(del, start);
	}
	// std::cout << s.substr(start, end - start);
}
int main(int argc, char const* argv[])
{
	// Takes C++ string with any separator
	std::string a = "Hi$%do$%you$%do$%!";
	tokenize(a, "$%");
	std::cout <<'\n';

	return 0;
}



std::map<char,int> myCounter(const std::string& s)
{
    std::map<char,int> C{};
    for(auto &i:s)
    {
        C[i]+=1;
    }
    return C;
}


std::string getLargestSubString(const std::string& s,int k)
{
    std::map<char,int> C{myCounter(s)};
    std::map<char,int>::iterator iter=C.begin();
    int sz=s.size();
    for(;iter!=C.end();++iter)
    {
        if(iter->second<k)
        {   
            std::vector<std::string> vec{};
            tokenize(s,iter->first,vec);
            // std::string s1=s.substr(0,iter->)
            
            return std::max(getLargestSubString(s.substr(0,iter->first),k),getLargestSubString(s.substr(k,sz-1),k));
        }
    }
    return s;
}

// int main()
// {
//     std::string s="abbbcccddee";
//     std::cout<<getLargestSubString(s,3);
// }

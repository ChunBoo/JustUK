//given some rules to get the words
//likes "C>H","H>U","U>N" --> "CHUN"
//Will use the set to get the unique chars
//use the map to get the sequence of the final word
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<iterator>
using DT=std::vector<std::string>;

std::string constructWord(const DT& rules)
{
     std::set<char> s{};
     std::map<char,char> m{};

     for(auto &rule:rules)
     {
          int pos=rule.find('>');
          s.insert(rule[pos-1]);
          s.insert(rule[pos+1]);
     }

     for(auto &rule:rules)
     {
          int pos=rule.find('>');
          s.erase(rule[pos+1]);
          m[rule[pos-1]]=rule[pos+1];
     }

     //get the first char now

     std::string ans{};
     std::set<char>::iterator iter=s.begin();

     char cur=*iter;

     ans+=cur;
     auto find=m.find(cur);
     while(find!=m.end())
     {
          cur=find->second;
          ans+=cur;
          find=m.find(cur);
     }
     return ans;
   //get the first char from set now
}

int main()
{
//     DT rules{"E>R","R>I","I>C"}; //rules=["E>R","R>I","I>C"]
    DT rules{"C>H","H>U","U>N"}; //rules=["E>R","R>I","I>C"]
    std::cout<<constructWord(rules);
    return 0;
}
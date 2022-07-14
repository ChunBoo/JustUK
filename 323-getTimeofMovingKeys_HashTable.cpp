//given a keyboards and one string,to return the total count of keys

#include<string>
#include<vector>
#include<iostream>
#include<map>

using STR=std::string;
using MAP=std::map<char,int>;


int getCount(const STR &keys, const STR &word)
{
    int kLen=keys.size(),wLen=word.size();
    if(!kLen ||!wLen)
        return 0;

    MAP m{};
    for(int i=0;i<kLen;++i)
    {
        m[keys[i]]=i;
    }

    int ans=m[word[0]];
    for(int i=1;i<wLen;++i)
        ans+=std::abs(m[word[i]]-m[word[i-1]]);
    return ans;
}

int main()
{
    STR keyboard = "abcdefghijklmnopqrstuvwxyz";
    STR word = "cba";
    std::cout<<getCount(keyboard,word);
    return 0;
}

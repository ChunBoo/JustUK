//given one string,return it's compressed results of runlength
//convert the integer to string method is std::to_string(intValue)
#include<string>
#include<iostream>

using DT=std::string;

DT runLengthCompressed(const DT& s)
{
    DT ans{};
    if(s.empty())
        return ans;
    int c=1,len=s.size();
    for(int i=1;i<len;++i)
    {
        if(s[i]==s[i-1])
            c+=1;
        else
        {
            ans+=std::to_string(c)+s[i-1];
            c=1;
        }
    }
    if(c>1)  //the last character should be consider
        ans+=std::to_string(c)+s[len-1];
    return ans;
}


int main()
{
    DT s="aabbbccccdddddeeeeee";
    DT ret=runLengthCompressed(s);
    std::cout<<ret<<'\n';
    return 0;
}
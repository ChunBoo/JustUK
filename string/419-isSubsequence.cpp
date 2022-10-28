#include<string>
#include<iostream>


using STR=std::string;

bool isSubSequence(const STR& s, const STR& t)
{
    if(s.size()>t.size())
        return false;
    
    int i=0,j=0;
    while(i<s.size() && j<t.size())
    {
        if(s[i]==t[j])
        {
            i+=1;
            j+=1;
        }
        else
            j+=1;
    }
    return i==s.size();
}
bool f(int i,int j,const STR& s, const STR& t)
{
    if(i==s.size())
        return true;
    if(j==t.size())
        return false;
    if(s[i]==t[j])
        return f(i+1,j+1,s,t);
    else
        return f(i,j+1,s,t);
}

bool isSubSequenceGreedy(const STR& s, const STR& t)
{
    if(s.size()>t.size())
        return false;
    return f(0,0,s,t);
}

int main()
{
    STR s="abc",t="ahbgdc" ;
    std::cout<<isSubSequence(s,t);
    std::cout<<isSubSequenceGreedy(s,t);
}
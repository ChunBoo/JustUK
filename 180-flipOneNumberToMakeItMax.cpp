//flip one bit of a number to make it as max,likes 123-->323,321-->331

#include<iostream>
#include<string>  //for std::stoi() and std::to_string()


int flipOneBitToMax(int val)
{
    if(val<=0)
        return 0;
    std::string sVal=std::to_string(val);

    int sz=sVal.size();
    for(int i=0;i<sz;++i)
    {
        if(sVal[i]!='3')
        {
            sVal[i]='3';
            break;
        }
    }
    return std::stoi(sVal);
}

int main()
{
    int v=323;
    std::cout<<flipOneBitToMax(v)<<'\n';
    return 0;
}

//given a line with max length,to make it as one rectangle
//return the max rectangles area

#include<iostream>

int getMaxHeight(int len,int& h,int &w)
{
    int f=-2*h*h+32*h;
    h=-1*32/(2*(-2));
    w=32-2*h;
}

int quadraticMethod(int length)
{
    int maxHeight=0,width=0;
    getMaxHeight(length,maxHeight,width);
    return maxHeight*width;
}


int bruteForceMethod(int length)
{
    if(length==0)
        return 0;

    int h=1,area=0;
    for(;h<length/2;++h)
    {
        int curArea=(length-2*h)*h;
        if(curArea>area)
        {
            area=curArea;
        }
    }
    return area;
}



int main()
{
    std::cout<<bruteForceMethod(32);
    std::cout<<quadraticMethod(32);
    return 0;
}
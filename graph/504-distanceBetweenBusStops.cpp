#include<iostream>
#include<vector>
#include<numeric>  //for std::accumulate


using VEC=std::vector<int>;

int shortestDistance(const VEC& dis,int start,int stop)
{
    int sum=std::accumulate(dis.begin(),dis.end(),0);
    if(stop<start)
    {
        int tmp=start;
        start=stop;
        stop=tmp;
    }
    int d1=std::accumulate(dis.begin()+start,dis.begin()+stop,0);
    return std::min(sum-d1,d1);

}

int main()
{
    VEC distance={1,2,3,4};
    int start=0,stop=1;
    std::cout<<shortestDistance(distance,start,stop);
}
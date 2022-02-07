//greedy algorithm
#include<algorithm>
#include<vector>
#include<iostream>

int completedTasks(std::vector<int>& tasks,std::vector<int> persons)
{
    std::sort(tasks.begin(),tasks.end());// must sorted those two arrays....the reason is what??
    std::sort(persons.begin(),persons.end());

    int ans=0;
    int t=0,p=0;
    while((t<tasks.size())&&(p<persons.size()))
    {
        if(tasks[t]<=persons[p])
        {
            ans+=1;
            t+=1;
        }
        p+=1;
    }
    return ans;
}

int main()
{
    std::vector<int> t{2,3,4,5};
    std::vector<int> p{6,2,1};
    int res=completedTasks(t,p);
    std::cout<<res<<'\n';
    return 0;
}
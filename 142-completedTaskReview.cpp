//given two arrays for tasks and persons respectively
// to get the total tasks which can be completed by given the person
//greedy 
#include<vector>
#include<iostream>
#include<algorithm>
int completedTasks(std::vector<int>& tasks,std::vector<int>& persons)
{
    if(persons.empty()||tasks.empty())
        return 0;
    //this two steps is very important 
    std::sort(tasks.begin(),tasks.end());
    std::sort(persons.begin(),persons.end());

    int tSize=tasks.size();
    int pSize=persons.size();
    int t=0,p=0,ans=0;

    while(t<tSize&& p<pSize)
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
    std::vector<int> tasks{2,3,4,5};
    std::vector<int> persons{6,2};

    int res=completedTasks(tasks,persons);

    std::cout<<res<<'\n';

    return 0;
}
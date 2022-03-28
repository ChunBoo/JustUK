//link: https://www.geeksforgeeks.org/minimum-number-operation-required-convert-number-x-y/

//given a target number and started number, return the minimum steps which can convert initialized number to target 
/*
Given a initial number x and two operations which are given below: 

Multiply number by 2.
Subtract 1 from the number.
The task is to find out minimum number of operation required to convert number x into y using only above two operations. We can apply these operations any number of times.
Constraints: 
1 <= x, y <= 1000
*/
#include<iostream>
// #include<deque>
#include<set>
#include<queue>

//BFS version
/*
The idea is to use BFS for this. We run a BFS and create nodes by multiplying with 2 and subtracting by 1, thus we can obtain all possible numbers reachable from starting number. 
Important Points : 
1) When we subtract 1 from a number and if it becomes < 0 i.e. Negative then there is no reason to create next node from it (As per input constraints, numbers x and y are positive). 
2) Also, if we have already created a number then there is no reason to create it again. i.e. we maintain a visited array. 
*/
struct Node
{
    int val;
    int level;
};

int BFSMethod(int start,int end)
{
    if(start==end)
        return 0;
    int ans=INT_FAST32_MAX;
    std::queue<Node> nb{};
    Node x{start,0};
    nb.push(x);
    std::set<int> visited{};
    while(!nb.empty())
    {
        Node curNode=nb.front();
        nb.pop();
        std::cout<<"curValue= "<<curNode.val<<'\n';
        int curValue=curNode.val;
        visited.insert(curValue);
        if(curValue==end)
            return curNode.level;
        if((curValue-1==end)&&(curValue*2==end))
            return curNode.level+1;
        //push the curValue*2 to queue
        if(visited.find(curValue*2)==visited.end())
            nb.push({curValue*2,curNode.level+1});
        if((curValue-1>0)&&visited.find(curValue-1)==visited.end())
            nb.push({curValue-1,curNode.level+1});
    }
    return ans;
}


int minimumStepsToConvert(int start,int end)
{
    int ans=0;
    if(start==end)
        return 0;
    
    while(start<end)
    {
        if(end&1) //end is odd number
        {
            end+=1;
        }
        else
            end/=2;
        ans+=1;
    }   
    return ans+(start-end);
}


int main()
{
    std::cout<<minimumStepsToConvert(1,60);
    // std::cout<<BFSMethod(1,60)<<'\n';
    return 0;
}
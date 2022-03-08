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
#include<deque>
#include<set>

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
    
    std::deque<Node> q;
    std::set<int> visited;
    Node f{start,0}; 
    q.push_back(f);
    while(!q.empty())
    {
        Node curNode=q.front();
        q.pop_front();
        if(curNode.val==end)
            return curNode.level;
        if(((curNode.val*2)==end)||((curNode.val-1)==end))
            return curNode.level+1;
        visited.insert(curNode.val);
        //add the curNode.val*2 into queue
        if(visited.find(curNode.val*2)==visited.end())
        {
            Node newNode{curNode.val*2,curNode.level+1};
            q.push_back(newNode);
        }
        //add the curNode.val-1 into queue
        if(visited.find(curNode.val-1)==visited.end())
        {
            Node newNode{curNode.val-1,curNode.level+1};
            q.push_back(newNode);
        }
    }
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
    // std::cout<<minimumStepsToConvert(2,5);
    std::cout<<BFSMethod(2,5)<<'\n';
    return 0;
}
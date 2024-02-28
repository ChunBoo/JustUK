
/*
You are given an integer n representing the number of nodes in a perfect binary tree consisting of nodes numbered from 1 to n. The root of the tree is node 1 and each node i in the tree has two children where the left child is the node 2 * i and the right child is 2 * i + 1.

Each node in the tree also has a cost represented by a given 0-indexed integer array cost of size n where cost[i] is the cost of node i + 1. You are allowed to increment the cost of any node by 1 any number of times.

Return the minimum number of increments you need to make the cost of paths from the root to each leaf node equal.

Note:

A perfect binary tree is a tree where each node, except the leaf nodes, has exactly 2 children.
The cost of a path is the sum of costs of nodes in the path.

Input: n = 7, cost = [1,5,2,2,3,3,1]
Output: 6
Explanation: We can do the following increments:
- Increase the cost of node 4 one time.
- Increase the cost of node 3 three times.
- Increase the cost of node 7 two times.
Each path from the root to a leaf will have a total cost of 9.
The total increments we did is 1 + 3 + 2 = 6.
It can be shown that this is the minimum answer we can achieve.

*/
// class Solution {
// public:
//     int minIncrements(int n, vector<int>& cost) {
//         int ans=0;
//         for(int i=n-2;i>0;i-=2)
//         {
//             ans+=abs(cost[i+1]-cost[i]);
//             cost[i/2]+=max(cost[i],cost[i+1]);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int minIncrements(int n, vector<int>& cost) {
//         return dfs(cost,1,n);
//     }
// private:
//     int dfs(vector<int>& cost,int root,int n)
//     {
//         if(2*root>n)
//             return 0;
//         int ans=dfs(cost,2*root,n)+dfs(cost,2*root-1,n);
//         if(cost[2*root]>cost[2*root-1])
//         {
//             ans+=(cost[2*root]-cost[2*root-1]);
//             cost[2*root-1]=cost[2*root];
//         }
//         else if(cost[2*root-1]>cost[2*root]){
//             ans+=(cost[2*root-1]-cost[2*root]);
//             cost[2*root]=cost[2*root-1];
//         }
//         cost[root]+=cost[2*root];
//         return ans;
//     }
// };


class Solution {
public:
    int res=0,n;
    int dfs(int index,vector<int>& cost){
        if(index*2>n)return cost[index-1];
        int left=dfs(index*2,cost);
        int right=dfs(index*2+1,cost);
        res+=abs(left-right);
        return max(left,right)+cost[index-1];
    }
    int minIncrements(int n, vector<int>& cost) {
        this->n=n;
        dfs(1,cost);
        return res;
    }
};
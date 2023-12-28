/**
 * You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.

paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.

Also, there is no garden that has more than 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden.  The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

Example 1:

Input: N = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Example 2:

Input: N = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]
Example 3:

Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]
Note:

1 <= N <= 10000
0 <= paths.size <= 20000
No garden has 4 or more paths coming into or leaving it.
It is guaranteed an answer exists.
Solution: Graph coloring, choose any available color
Time complexity: O(|V|+|E|)
Space complexity: O(|V|+|E|)
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n,0);
        vector<vector<int>> g(n);
        for(const auto&p:paths){
            g[p[0]-1].push_back(p[1]-1);
            g[p[1]-1].push_back(p[0]-1);
        }
        for(int i=0;i<n;++i){
            int mask=0;
            for(const auto& j:g[i])
                mask|=(1<<ans[j]);
            for(int c=1;c<=4&&ans[i]==0;++c){
                if(!(mask&(1<<c))) ans[i]=c;
            }
        }
            return ans;

    }
};

int main()
{
    int N = 3;
    vector<vector<int>> paths = {{1,2},{2,3},{3,1}};
    vector<int> res=Solution().gardenNoAdj(N,paths);
    for(const auto& v:res)
        cout<<v<<',';
}
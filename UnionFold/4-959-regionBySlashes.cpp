/**
 * Disjoint Set Union (DSU), also known as Union-Find, is a data structure that keeps track of a partition of a set into disjoint (non-overlapping) subsets. It provides near-constant-time operations for two useful operations:

1. Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.

2. Union: Join two subsets into a single subset.

In computer science, it is used for various applications, such as in Kruskal's algorithm for finding the minimum spanning tree of a graph, in network connectivity, image processing, and many more.
*/
/**
 * In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.

Example 1:

Input:[  " /",  "/ "]
Output: 2
Explanation: The 2x2 grid is as follows:
*/
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        DSU dsu(4*n*n);
        for(int r=0;r<n;++r){
            for(int c=0;c<n;++c){
                int index=4*(r*n+c);
                switch(grid[r][c]){
                    case '/':
                      dsu.merge(index+0,index+3);
                      dsu.merge(index+1,index+2);
                      break;
                    case '\\':
                        dsu.merge(index+0,index+1);
                        dsu.merge(index+2,index+3);
                        break;
                    case ' ':
                        dsu.merge(index+0,index+1);
                        dsu.merge(index+1,index+2);
                        dsu.merge(index+2,index+3);
                        break;
                    default:
                        break;
                }
                if(r+1<n)
                    dsu.merge(index+2,index+4*n+0);
                if(c+1<n)
                    dsu.merge(index+1,index+4+3);
            }
             
        }
        int ans=0;
        for(int i=0;i<4*n*n;++i)
        if(dsu.find(i)==i)
            ++ans;
        return ans;
    }

private:
    class DSU{
        public:
            DSU(int n):p_(n)
            {
                for(int i=0;i<n;++i)
                    p_[i]=i;
            }
            int find(int x){
                if(x!=p_[x])
                    p_[x]=find(p_[x]);
                return p_[x];
            }
            void merge(int x,int y)
            {
                p_[find(x)]=find(y);
            }

        private:
            vector<int> p_;
    

    };
};
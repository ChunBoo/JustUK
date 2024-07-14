/***
 * There is a city composed of n x n blocks, where each block contains a single building shaped like a vertical square prism. You are given a 0-indexed n x n integer matrix grid where grid[r][c] represents the height of the building located in the block at row r and column c.

A city's skyline is the outer contour formed by all the building when viewing the side of the city from a distance. The skyline from each cardinal direction north, east, south, and west may be different.

We are allowed to increase the height of any number of buildings by any amount (the amount can be different per building). The height of a 0-height building can also be increased. However, increasing the height of a building should not affect the city's skyline from any cardinal direction.

Return the maximum total sum that the height of the buildings can be increased by without changing the city's skyline from any cardinal direction.
 */

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        const int n=grid.size();
        vector<int> rowMax(n), colMax(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                rowMax[i]=max(rowMax[i],grid[i][j]);
                colMax[j]=max(colMax[j],grid[i][j]);
            }
        }
        int ans=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                ans+=min(rowMax[r],colMax[c])-grid[r][c];
            }
        }
        return ans;
    }
};
/**
 * @brief You are given a 0-indexed 2D integer matrix grid of size 3 * 3, representing the number of stones in each cell. The grid contains exactly 9 stones, and there can be multiple stones in a single cell.

In one move, you can move a single stone from its current cell to any other cell if the two cells share a side.

Return the minimum number of moves required to place one stone in each cell.
 * 
 */

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int,int>> more,less;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]>1){
                    for(int k=2;k<=grid[i][j];k++){
                        more.emplace_back(i,j);
                    }
                }
                else if(grid[i][j]==0){
                    less.emplace_back(i,j);
                }
            }
        }
        int ans=INT_MAX;
        do{
            int steps=0;
            for(int i=0;i<more.size();i++){
                steps+=abs(more[i].first-less[i].first)+abs(more[i].second-less[i].second);
            }
            ans=min(ans,steps);
        }while(next_permutation(more.begin(),more.end()));
        return ans;
    }
};
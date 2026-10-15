class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    maxArea = std::max(maxArea, dfs(i, j, grid));
                }
            }
        }
        return maxArea;
    }
    int dfs(int x, int y, vector<vector<int>>& grid){
        if(x<0 || x>= grid.size() || y<0 || y>= grid[x].size() || grid[x][y]!=1){
            return 0;
        }
        grid[x][y]=-1;
        int count = 1;
        vector<vector<int>> directions = {{1,0},{0,1},{-1, 0}, {0, -1}};
        for(auto direction: directions){
            count += dfs(x+direction[0], y+ direction[1], grid);
        }
        return count;
    }
};

class Solution {
private:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size() || grid[row][col]!=0){
            return 0;
        }
        if(row == grid.size()-1 && col == grid[row].size()-1){ return 1; }
        // grid[row][col] = -1;
        if(dp[row][col]!=-1){ return dp[row][col]; }
        int count = 0;
        vector<vector<int>> directions = {{0,1},{1,0}};
        for(auto it: directions){
            count += dfs(grid, row+it[0], col+it[1]);
        }
        return dp[row][col]=count;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        dp.assign(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(),-1));
        return dfs(obstacleGrid, 0, 0); 
    }
};
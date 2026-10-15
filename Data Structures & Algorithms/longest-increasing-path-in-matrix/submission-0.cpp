class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int result = 0;
        dp.assign(matrix.size()+1, vector<int>(matrix[0].size()+1, -1));
        for(int row = 0;row<matrix.size();row++){
            for(int col = 0;col<matrix[row].size();col++){
                result = max(result, dfs(matrix, row, col, INT_MIN));
            }
        }
        return result;
    }
private:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix, int row, int col, int prevValue){
        if(row < 0 || row >= matrix.size() || col <0 || col >= matrix[row].size() || matrix[row][col] <=prevValue){
            return 0;
        }
        if(dp[row][col] != -1){ return dp[row][col]; }
        int res = 1;
        for(auto d:directions){
            res = max(res, 1+dfs(matrix, row+d[0],col+d[1], matrix[row][col]));
        }
        return dp[row][col] = res;
    }
};

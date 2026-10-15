class Solution {
public:
    int minDistance(string word1, string word2) {
        dp.assign(word1.size()+1, vector<int>(word2.size()+1, -1));
        return dfs(word1, 0, word2, 0);
    }
private:
    vector<vector<int>> dp;
    int dfs(string word1, int i, string word2, int j){
        if(i == word1.size()){ return word2.size() - j; }
        if(word2.size() == j){ return word1.size() - i; }
        if(dp[i][j]!=-1){ return dp[i][j]; }
        if(word1[i] == word2[j]){
            dp[i][j] = dfs(word1,i+1, word2, j+1);
        }else{
            int res = min(dfs(word1,i+1, word2,j),dfs(word1,i, word2,j+1));
            res = min(res, dfs(word1,i+1,word2, j+1));
            dp[i][j] = res+1;
        }
        return dp[i][j];
    }
};

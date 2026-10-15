class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.size() > s.size()){ return 0; }
        dp.assign(s.size()+1, vector<int>(t.size()+1, -1));
        return dfs(s,0, t, 0);
    }
private:
    vector<vector<int>> dp;
    int dfs(string s, int i, string t, int j){
        if(j == t.size()){ return 1; }
        if(i == s.size()){ return 0; }
        if(dp[i][j]!=-1){ return dp[i][j]; }
        int res = dfs(s,i+1,t, j);
        if(s[i] == t[j]){
            res += dfs(s,i+1, t, j+1);
        }
        return dp[i][j] = res;
    }
};

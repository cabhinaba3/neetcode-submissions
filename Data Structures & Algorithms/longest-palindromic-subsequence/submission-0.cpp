class Solution {
public:
    int longestPalindromeSubseq(string s) {
        dp.assign(s.size(), vector<int>(s.size(), -1));
        return dfs(s, 0, (int)s.size()-1);
    }
private:
    vector<vector<int>> dp;
    int dfs(string s, int left, int right){
        if(left > right){ return 0; }
        if(left == right) { return 1; }
        if(dp[left][right]!=-1){ return dp[left][right]; }
        int value = 0;
        if(s[left] == s[right]){
            value = 2+dfs(s, left+1, right-1);
        }else{
            value = std::max(dfs(s,left+1,right), dfs(s, left, right-1));
        }
        return dp[left][right] = value;
    }
};
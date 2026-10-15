class Solution {
public:
    vector<vector<int>> dp;
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){ return false; }
        dp.assign(s1.size()+1, vector<int>(s2.size()+1, -1));
        return dfs(s1, 0, s2, 0, s3, 0);
    }
    bool dfs(string s1, int i, string s2, int j, string s3, int k){
        if(k == s3.size()){
            return (i == s1.size()) && (j == s2.size());
        }
        if(dp[i][j] !=-1){ return dp[i][j]; }
        int flag = 0;
        if(i < s1.size() && s1[i] == s3[k]){
            flag = flag || dfs(s1,i+1,s2,j,s3,k+1);
        }
        if(j < s2.size() && s2[j] == s3[k]){
            flag = flag || dfs(s1,i,s2,j+1,s3,k+1);
        }
        return dp[i][j] = flag;
    }
};

class Solution {
private:
    vector<int> dp;
    int dfs(string s, int index){
        if(index == s.size()){ return 1; }
        if(s[index] == '0'){ return 0; }
        if(dp[index] != -1){ return dp[index]; }
        int result = dfs(s, index+1);
        if(index < s.size()-1){
            if(s[index] == '1' || (s[index] == '2' && s[index+1]<='6')){
                result += dfs(s, index+2);
            }
        }
        return dp[index] = result;
    }
public:
    int numDecodings(string s) {
        dp.assign(s.size()+1, -1);
        return dfs(s, 0);
    }
};

class Solution {
public:
    unordered_map<int, bool> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        // unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        dp[s.size()] = true;
        return dfs(s, wordDict, 0);
    }
    bool dfs(string s, vector<string>& wordDict, int index){
        if(dp.find(index)!= dp.end()){ return dp[index]; }

        for(const string& w: wordDict){
            if(index+w.size() <= s.size() && s.substr(index, w.size())==w){
                if(dfs(s, wordDict, index+w.size())){
                    dp[index] = true;
                    return true;
                }
            }
        }
        dp[index] = false;
        return false;
    }
};

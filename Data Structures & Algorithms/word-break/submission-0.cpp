class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return dfs(s, wordSet, 0);
    }
    bool dfs(string s, const unordered_set<string>& wordSet, int index){
        if(index == s.size()){ return true; }
        for(int j=index;j<s.size();j++){
            if(wordSet.find(s.substr(index, j-index+1))!= wordSet.end()){
                if(dfs(s, wordSet, j+1)){
                    return true;
                }
            }
        }
        return false;
    }
};

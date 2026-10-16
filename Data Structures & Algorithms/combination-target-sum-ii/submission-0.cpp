class Solution {
private:
    set<vector<int>> res;
    void dfs(vector<int>& candidates, int target, vector<int>& current, int index){
        if(target == 0){
            res.insert(current);
            return;
        }
        if(target<0 || index >= candidates.size()){ return; }
        current.push_back(candidates[index]);
        dfs(candidates, target-candidates[index], current, index+1);
        current.pop_back();
        dfs(candidates, target, current,index+1);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        dfs(candidates, target, current, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }
};

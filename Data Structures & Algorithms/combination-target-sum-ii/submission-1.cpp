class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int index, vector<int> path,int target){
        if(target == 0){ ans.push_back(path);}
        else{
            for(int i=index;i<nums.size();i++){
                if(i>index && nums[i]==nums[i-1]){ continue; }
                if(nums[i]>target){ break; }
                path.push_back(nums[i]);
                dfs(nums, i+1,path, target-nums[i]);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0, {}, target);
        return ans;
    }
};

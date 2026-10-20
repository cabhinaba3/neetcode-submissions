class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int index, vector<int> sub){
        if(index == nums.size()){ ans.push_back(sub); }
        else{
            sub.push_back(nums[index]);
            dfs(nums, index+1, sub);
            sub.pop_back();

            while(index+1 < nums.size() && nums[index] == nums[index+1]){ index++; }
            dfs(nums, index+1, sub);
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums,0, {});
        return ans;
    }
};

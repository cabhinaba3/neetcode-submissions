class Solution {
private:
    vector<vector<int>> sub;
    void dfs(vector<int>& nums, int index, vector<int>& values){
        if(index ==  nums.size()){
            sub.push_back(values);
            return;
        }
        values.push_back(nums[index]);
        dfs(nums, index+1, values);
        values.pop_back();
        dfs(nums, index+1, values);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> values;
        dfs(nums, 0, values);
        return sub;
    }
};

class Solution {
public:
    int dfs(vector<int>& nums, int index, bool first){
        if(index >= nums.size())return 0;
        if(index == 0){
            return max(dfs(nums,index+1, false),nums[index]+dfs(nums, index+2, true));
        }else if(index<nums.size()-1){
            return max(dfs(nums,index+1, first),nums[index]+dfs(nums, index+2, first));
        }else if(index == nums.size()-1){
            if(first == false){
                return max(dfs(nums,index+1, false),nums[index]+dfs(nums, index+2, false));
            }else{
                max(dfs(nums,index+1, true),nums[index]+dfs(nums, index+2, true));
            }
        }
        return 0;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}
        return dfs(nums, 0, false);
    }
};

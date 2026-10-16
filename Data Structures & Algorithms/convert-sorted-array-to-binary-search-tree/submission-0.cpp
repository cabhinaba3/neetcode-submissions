class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums,0, nums.size()-1);
    }
    TreeNode *dfs(vector<int>& nums, int left, int right){
        if(left > right){ return nullptr; }
        int mid = (left + right)/2;
        TreeNode *newNode = new TreeNode(nums[mid]);
        newNode->left = dfs(nums,left, mid-1);
        newNode->right = dfs(nums, mid+1, right);
        return newNode;
    }
};

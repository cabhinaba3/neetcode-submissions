/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
// private:
//     bool dfs(TreeNode *root, int targetSum){

//     }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // return dfs(root, targetSum);
        if(root == nullptr){ return false; }
        if(root->left == nullptr && root->right == nullptr){
            return targetSum == root->val;
        }
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }

};
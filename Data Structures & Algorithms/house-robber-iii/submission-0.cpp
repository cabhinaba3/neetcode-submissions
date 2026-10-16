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
private:
    unordered_map<TreeNode*, int> memo;
    int dfs(TreeNode* root) {
        if(root == nullptr){ return 0; }
        if(memo.find(root) != memo.end()){ return memo[root]; }
        int amount = root->val;
        if(root->left){
            amount += dfs(root->left->left)+dfs(root->left->right);
        }
        if(root->right){
            amount += dfs(root->right->left)+dfs(root->right->right);
        }
        return memo[root] = std::max(amount, dfs(root->left)+dfs(root->right));
    }
public:
    int rob(TreeNode *root){
        // memo[nullptr] = 0;
        return dfs(root);
    }
};
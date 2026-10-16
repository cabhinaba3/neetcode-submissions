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
    int dfs(TreeNode *node, int value){
        if(node == nullptr){ return 0; }
        int result = (node->val >= value) ? 1:0;
        value = std::max(value, node->val);
        result += dfs(node->left, value);
        result += dfs(node->right, value);
        return result;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};

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
    int countNodes(TreeNode *root){
        if(root == nullptr){ return 0; }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    bool dfs(TreeNode *node, int index, int numNodes){
        if(node == nullptr){ return true; }
        if(index >= numNodes){ return false; }
        return dfs(node->left, 2*index+1, numNodes) && dfs(node->right, 2*index+2, numNodes);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int numNodes = countNodes(root);
        return dfs(root, 0, numNodes);
    }
};
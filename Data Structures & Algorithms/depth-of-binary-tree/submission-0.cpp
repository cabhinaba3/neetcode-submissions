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
    int maxDepthValue = 0;
public:
    int maxDepth(TreeNode* root) {
        util(root, 0);
        return maxDepthValue;
    }
    void util(TreeNode *root, int depth){
        if(root == nullptr){
            maxDepthValue = max(maxDepthValue, depth);
            return;
        }
        util(root->left, depth+1);
        util(root->right, depth+1);
    }
};

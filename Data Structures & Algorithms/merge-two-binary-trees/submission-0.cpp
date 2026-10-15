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
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return mergeUtil(root1, root2);
    }
private:
    // bool isLeaf(TreeNode *root){
    //     return root->left == nullptr && root->right == nullptr;
    // }
    TreeNode* mergeUtil(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr && root2 == nullptr){ return nullptr; }
        TreeNode *node;
        if(root1 != nullptr && root2 != nullptr){
            node = new TreeNode(root1->val+root2->val);
            node->left = mergeUtil(root1->left, root2->left);
            node->right = mergeUtil(root1->right, root2->right);
        }else if(root1 == nullptr && root2 != nullptr){
            node = new TreeNode(root2->val);
            node->left = mergeUtil(root1, root2->left);
            node->right = mergeUtil(root1, root2->right);
        }else if(root1 != nullptr && root2 == nullptr){
            node = new TreeNode(root1->val);
            node->left = mergeUtil(root1->left, root2);
            node->right = mergeUtil(root1->right, root2);
        }
        return node;
    }
};
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
    unordered_map<TreeNode*, int> cache;
public:
    int rob(TreeNode* root) {
       if(root == nullptr){ return 0; }
       if(cache.find(root) != cache.end()){ return cache[root]; }
       int amount = root->val;
       if(root->left != nullptr){
        amount += rob(root->left->left)+rob(root->left->right);
       }
       if(root->right != nullptr){
        amount += rob(root->right->left)+rob(root->right->right);
       }
       return cache[root] = std::max(amount, rob(root->left)+rob(root->right));
    }
};
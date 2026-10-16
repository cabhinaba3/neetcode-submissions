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
    bool isLeaf(TreeNode *root){
        return root->left == nullptr && root->right == nullptr;
    }
    int dfs(TreeNode *root, int num){
        if(root == nullptr){ return 0; }
        num = num * 10 + root->val;
        if(isLeaf(root)){ return num; }
        return dfs(root->left, num) + dfs(root->right, num);
        // if(isLeaf(root)){ return make_pair(root->val,1); }
        // auto left = dfs(root->left);
        // auto right = dfs(root->right);
        // int value = pow(10,right.second)+pow(10,left.second)+root->val;
        // printf("%d--\n",value);
        // return make_pair(value + left.first +right.first, std::max(left.second, right.second)+1);
    }
public:
    int sumNumbers(TreeNode* root) {
        // if(root == nullptr){ return 0; }
        return dfs(root,0);
    }
};
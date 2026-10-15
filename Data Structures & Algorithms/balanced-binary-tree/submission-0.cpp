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
    pair<int,bool> dfs(TreeNode* root){
        if(root == nullptr){ return make_pair(0, true);}
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if(abs(left.first-right.first)<=1 && left.second == true && right.second == true){
            return make_pair(1+std::max(left.first,right.first), true);
        }else{
            return make_pair(1+std::max(left.first,right.first), false);
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).second;
    }
};

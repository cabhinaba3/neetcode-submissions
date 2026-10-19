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
    vector<int> dfs(TreeNode *root){
        if(root == nullptr){ return {}; }
        if(root->left == nullptr && root->right == nullptr){ return {root->val}; }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        vector<int> leafNodes;
        for(auto it: left){ leafNodes.push_back(it); }
        for(auto it: right){ leafNodes.push_back(it); }
        return leafNodes;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leftNodes = dfs(root1);
        vector<int> rightNodes = dfs(root2);
        if(leftNodes.size() != rightNodes.size()){ return false; }
        for(int i=0;i<leftNodes.size();++i){
            if(leftNodes[i]!=rightNodes[i]){ return false; }
        }
        return true;
    }
};

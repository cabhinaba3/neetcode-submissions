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
vector<int> dfs(TreeNode *root){
    if(root == nullptr){ return {}; }
    if(root->left == nullptr && root->right == nullptr){
        return {root->val};
    }
    auto left = dfs(root->left);
    auto right = dfs(root->right);
    vector<int> leafNodes;
    for(auto it: left){ leafNodes.push_back(it); }
    for(auto it: right){ leafNodes.push_back(it); }
    return leafNodes;
}
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafNodes1 = dfs(root1);
        vector<int> leafNodes2 = dfs(root2);
        if(leafNodes1.size() != leafNodes2.size()){ return false; }
        for(int i=0;i<leafNodes1.size();++i){
            if(leafNodes1[i]!=leafNodes2[i]){ return false; }
        }
        return true;
    }
};

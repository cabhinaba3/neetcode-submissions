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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        stack<pair<TreeNode*, int>> st;
        st.push(make_pair(root, 0));
        while(!st.empty()){
            auto [node, depth] = st.top();
            st.pop();
            if(node == nullptr){ continue; }
            if(results.size() == depth){ results.push_back({}); }
            st.push(make_pair(node->right, depth+1));
            st.push(make_pair(node->left, depth+1));
            results[depth].push_back(node->val);
        }
        for(int i=0;i<results.size();i++){
            if(i&1){ reverse(results[i].begin(), results[i].end()); }
        }
        return results;
    }
};
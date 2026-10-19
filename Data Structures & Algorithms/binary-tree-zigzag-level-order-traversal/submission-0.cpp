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
    vector<vector<int>> res;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        st.push(make_pair(root,0));
        // int depth = 0;
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            if(node.first == nullptr){ continue; }
            if(res.size() == node.second){ res.push_back({}); }
            st.push(make_pair(node.first->right, node.second+1));
            st.push(make_pair(node.first->left, node.second+1));
            res[node.second].push_back(node.first->val);
        }
        for(int i=0;i<res.size(); ++i){
            if(i&1){ reverse(res[i].begin(), res[i].end()); }
        }
        return res;
    }
};
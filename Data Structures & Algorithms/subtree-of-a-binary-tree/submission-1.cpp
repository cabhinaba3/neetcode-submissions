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
    string serialise(TreeNode *root){
        if(root == nullptr){ return "$#"; }
        return "$"+ to_string(root->val)+serialise(root->left)+serialise(root->right);
    }
    vector<int> zFunction(string s){
        vector<int> z(s.size());
        int left = 0, right = 0;
        for(int i=1;i<s.size();i++){
            if(i<=right){
                z[i] = min(right - i +1, z[i-left]);
            }
            while(i+z[i]<s.size() && s[z[i]] == s[i+z[i]]){
                z[i]++;
            }
            if(i+z[i]-1>right){
                left = i;
                right = i+z[i]-1;
            }
        }
        return z;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string root_resialised = serialise(root);
        string subroot_serialised = serialise(subRoot);

        string combined = subroot_serialised + "|" + root_resialised;
        vector<int> zValues = zFunction(combined);
        int subLen = subroot_serialised.size();
        for(int i=subLen+1;i<combined.size();i++){
            if(zValues[i] == subLen){return true;}
        }
        return false;
    }
};

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
    bool solve(TreeNode* left, TreeNode* right){
        if(!left || !right){
            if(left != right) return false;
            return true;
        }
        if(left->val != right->val) return false;
        
        if(!solve(left->right, right->left)) return false;
        if(!solve(left->left, right->right)) return false;
        return true;
    }
        
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};
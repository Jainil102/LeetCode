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
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right) return true;
        if(!root->left || !root->right) return false;
        stack<TreeNode*> sl;
        stack<TreeNode*> sr;
        sl.push(root->left);
        sr.push(root->right);
        while(!sl.empty() || !sr.empty()){
            TreeNode* l = sl.top(); 
            sl.pop();
            TreeNode* r = sr.top(); 
            sr.pop();
            if(l->val != r->val) return false;
            
            if(l->left == NULL && r->right != NULL) return false;
            else if(l->left != NULL && r->right == NULL) return false;
            else if(l->left != NULL && r->right != NULL){
                sl.push(l->left);
                sr.push(r->right);
            }
            
            if(l->right == NULL && r->left != NULL) return false;
            else if(l->right != NULL && r->left == NULL) return false;
            else if(l->right != NULL && r->left != NULL){
                sl.push(l->right);
                sr.push(r->left);
            }
        }
        return true;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(node == NULL){
            return NULL;
        }
        
        TreeNode* a = solve(node->left, p, q, ans);
        TreeNode* b = solve(node->right, p, q, ans);
            
        if(!a && !b){
            if(node == p || node == q){
                return node;
            }    
            return NULL;
        }   
        
        if(a && b){
            ans = node;
            return NULL;
        }
        
        if(node == p || node == q){
            ans = node;
            return NULL;
        }   
        else{
            return node;
        }
        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        solve(root, p, q, ans);
        return ans;
    }
};
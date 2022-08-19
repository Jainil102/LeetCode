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
    int solve(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(node == NULL){
            return NULL;
        }
        
        int a = solve(node->left, p, q, ans);
        if(a == 2) return 2;
        int b = solve(node->right, p, q, ans);
        if(b == 2) return 2;
        
        if(!a && !b){
            if(node == p || node == q){
                return 1;
            }    
            return 0;
        }   
        
        if(a && b){
            ans = node;
            return 2;
        }
        
        if(node == p || node == q){
            ans = node;
            return 2;
        }   
        else{
            return 1;
        }
        return 0;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        solve(root, p, q, ans);
        return ans;
    }
};
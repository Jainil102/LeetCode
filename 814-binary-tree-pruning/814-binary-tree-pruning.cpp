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
    int postorder(TreeNode* &node){
        if(node == NULL) return 0;
        
        int a = postorder(node->left);
        int b = postorder(node->right);
        if(a==0 && b==0 && node->val==0){
            node = NULL;
            return 0;
        }
        return 1;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        postorder(root);
        return root;
    }
};
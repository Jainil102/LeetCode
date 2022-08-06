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
    int height(TreeNode* node, int* maxD){
        if(node == NULL) return 0;
        
        int l = height(node->left, maxD);
        int r = height(node->right, maxD);
        
        *maxD = max(*maxD, l+r);
        
        return 1 + max(l,r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD = 0;
        height(root, &maxD);
        return maxD;
    }
};
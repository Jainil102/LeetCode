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
    int height(TreeNode* node, int* maxSum){
        if(!node) return 0;
        
        int l = height(node->left, maxSum);
        int r = height(node->right, maxSum);
        
        int currMax = max(l,r) + node->val;
        currMax = max(currMax, node->val);
        
        *maxSum = max(*maxSum, max(currMax, l+r+node->val));
        
        return currMax; 
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        height(root, &maxSum);
        return maxSum;
    }
};
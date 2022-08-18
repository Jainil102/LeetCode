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
    bool preorder(TreeNode* node, TreeNode* target, vector<TreeNode*> &ans){  
        if(node == NULL) return false;

        ans.push_back(node);
        if(node == target) return true;

        if(preorder(node->left, target, ans) || 
            preorder(node->right, target, ans)) return true;

        ans.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path;
        preorder(root, p, p_path);
        vector<TreeNode*> q_path;
        preorder(root, q, q_path);
        TreeNode* ans;
        int i=0;
        while(i<p_path.size() && i<q_path.size() && p_path[i] == q_path[i]){
            ans = p_path[i++];
        }
        return ans;
    }
};
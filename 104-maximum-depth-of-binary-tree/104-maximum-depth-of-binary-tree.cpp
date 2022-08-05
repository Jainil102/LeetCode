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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == NULL) return 0;
        q.push(root);
        int height = 0, len;
        TreeNode* front;
        while(!q.empty()){
            len = q.size();
            for(int i=0; i<len; i++){
                front = q.front();
                if(front->left != NULL) q.push(front->left);
                if(front->right != NULL) q.push(front->right);
                q.pop();
            }
            height++;
        }
        return height;
    }
};
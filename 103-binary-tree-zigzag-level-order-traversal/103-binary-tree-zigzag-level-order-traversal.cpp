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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        int right = -1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            TreeNode* front;
            for(int i=0; i<size; i++){
                front = q.front();
                if(right == 1){
                    temp[size-1-i] = front->val;
                }
                else{
                    temp[i] = front->val;
                }
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                q.pop();
            }
            right = -right;
            ans.push_back(temp);
        }
        return ans;
    }
};
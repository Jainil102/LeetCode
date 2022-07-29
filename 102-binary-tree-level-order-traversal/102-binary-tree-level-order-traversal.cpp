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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            vector<TreeNode*> q1;
            while(!q.empty()){
                // ListNode* a = q.front();
                temp.push_back(q.front()->val);
                q1.push_back(q.front());
                q.pop();
            }
            ans.push_back(temp);
            for(int i=0; i<q1.size(); i++){
                if(q1[i]->left != NULL){
                    q.push(q1[i]->left);
                }
                if(q1[i]->right != NULL){
                    q.push(q1[i]->right);
                }
            }
        }
        return ans;
    }
};
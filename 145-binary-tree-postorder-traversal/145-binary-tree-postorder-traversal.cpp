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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp = s.top();
            if(temp->left) s.push(temp->left);
            else{
                if(temp->right) s.push(temp->right);
                else{
                    ans.push_back(temp->val);
                    s.pop();
                    while(!s.empty() && (s.top()->right == temp || s.top()->right == NULL)){
                        temp = s.top();
                        ans.push_back(temp->val);
                        s.pop();
                    }
                    if(s.empty()) break;
                    s.push(s.top()->right);
                }
            }
        }
        return ans;
    }
};
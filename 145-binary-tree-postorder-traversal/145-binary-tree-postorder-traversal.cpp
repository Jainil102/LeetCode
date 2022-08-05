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
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr!=NULL || !s.empty()){
            if(curr != NULL){
                s.push(curr);                
                curr = curr->left;
            }
            else{
                TreeNode* top = s.top();
                if(top->right == NULL){
                    while(!s.empty() && top->right == NULL){
                        ans.push_back(top->val);
                        s.pop();
                        while(!s.empty() && s.top()->right == top){
                            ans.push_back(s.top()->val);
                            top = s.top();
                            s.pop();    
                        }
                        if(!s.empty()){
                            top = s.top();
                        }
                    }
                    if(!s.empty()){
                        curr = top->right;
                    }
                }
                else{
                    curr = top->right;
                }
            }
        }
        return ans;
    }
};
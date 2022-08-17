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
    
    void solve(TreeNode* node, vector<int> &ans, int currLvl, int* maxLvl){
        if(node == NULL){
            return;
        }
        
        if(currLvl == *maxLvl){
            ans.push_back(node->val);
            *maxLvl = *maxLvl + 1;
        }
        
        solve(node->right, ans, currLvl+1, maxLvl);
        solve(node->left, ans, currLvl+1, maxLvl);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        int maxLvl = 0;
        solve(root, ans, 0, &maxLvl);
        return ans;
    }
};
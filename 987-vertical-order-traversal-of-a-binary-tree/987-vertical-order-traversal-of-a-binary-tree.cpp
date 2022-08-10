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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        map<int, map<int, multiset<int>>> m;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x = temp.second.first;
            int y = temp.second.second;
            m[x][y].insert(temp.first->val);
            if(temp.first->left) q.push({temp.first->left, {x-1, y+1}});
            if(temp.first->right) q.push({temp.first->right, {x+1, y+1}});
        }
        
        vector<vector<int>> ans;
        for(auto p : m){
            vector<int> col;
            for(auto q : p.second){
                for(auto r : q.second){
                    col.push_back(r);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};
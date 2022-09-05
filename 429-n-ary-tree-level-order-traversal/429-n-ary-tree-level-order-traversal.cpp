/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<vector<Node*>> q;
        q.push({root});
        while(!q.empty()){
            int size = q.size();
            vector<Node*> t;
            vector<int> temp;
            for(int i=0; i<size; i++){
                t = q.front();
                q.pop();
                for(int j=0; j<t.size(); j++){
                    temp.push_back(t[j]->val);
                    q.push(t[j]->children);   
                }
            }
            if(temp.size() > 0) ans.push_back(temp);
        }
        return ans;
    }
};
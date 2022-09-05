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
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            Node* t;
            vector<int> temp;
            for(int i=0; i<size; i++){
                t = q.front();
                q.pop();
                temp.push_back(t->val);
                for(int j=0; j< (t->children).size(); j++){
                    q.push((t->children)[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
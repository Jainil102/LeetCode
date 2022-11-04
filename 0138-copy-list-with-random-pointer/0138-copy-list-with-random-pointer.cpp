/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> umap; 
        Node* newHead = new Node(0);
        Node* temp = head;
        Node* temp1 = newHead;
        while(temp != NULL){
            temp1->next = new Node(temp->val);
            umap[temp] = temp1->next;
            temp1 = temp1->next;
            temp = temp->next;
        }
        umap[NULL] = NULL;
        
        temp = head;
        while(temp != NULL){
            umap[temp]->random = umap[temp->random];
            temp = temp->next;
        }
        
        return newHead->next;
    }
};
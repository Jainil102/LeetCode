/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        while(temp != NULL){
            if(temp->child != NULL){
                Node* next = temp->next;
                temp->next = temp->child;
                (temp->child)->prev = temp;
                Node* temp2 = temp->child;
                while(temp2->next != NULL){
                    temp2 = temp2->next;
                }
                temp2->next = next;
                if(next != NULL)next->prev = temp2;
                temp->child = NULL;
            }
            temp = temp->next;
        }
        return head;
    }
};
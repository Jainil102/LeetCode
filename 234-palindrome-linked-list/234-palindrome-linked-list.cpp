/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL){
            return true;
        }
        if((head->next)->next == NULL){
            if(head->val == (head->next)->val){
                return true;
            }
            return false;
        }
        
        ListNode* s = head;
        ListNode* f = head;
        
        while(f->next != NULL && (f->next)->next != NULL){
            s = s->next;
            f = (f->next)->next;
        }
        s = s->next;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        while(curr != s){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* t = prev;
        if(f->next == NULL){
            t = t->next;
        }
        
        while(s != NULL){
            if(s->val != t->val){
                return false;
            }
            s = s->next;
            t = t->next;
        }
        return true;
    }
};
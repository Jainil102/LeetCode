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
        
        ListNode* s = head;
        ListNode* f = head;
        
        while(f->next != NULL && (f->next)->next != NULL){
            s = s->next;
            f = (f->next)->next;
        }
        s = s->next;
        
        ListNode* prev = NULL;
        ListNode* curr = s;
        ListNode* next;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        s = prev;        
        f = head;
        
        while(s != NULL){
            if(s->val != f->val){
                return false;
            }
            s = s->next;
            f = f->next;
        }
        return true;
    }
};
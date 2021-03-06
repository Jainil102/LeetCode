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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int a = 0;
        ListNode head(0);
        ListNode* curr = &head;
        while(l1!=NULL || l2!=NULL){
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;
            a = x + y + carry;
            carry = a/10;
            a = a%10;
            
            curr->next = new ListNode(a);
            curr = curr->next;
                        
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }
        
        if(carry > 0){
            curr->next = new ListNode(carry);
        }
        
        return head.next;
    }
};
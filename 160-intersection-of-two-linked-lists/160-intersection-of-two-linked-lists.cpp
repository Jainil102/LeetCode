/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        
        ListNode* ta = headA;
        ListNode* tb = headB;
        
        while(ta != tb){
            ta = ta == NULL ? headB : ta->next;
            tb = tb == NULL ? headA : tb->next;
        }
        
        return ta;
    }
};
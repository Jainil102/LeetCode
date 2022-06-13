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
            if(ta == NULL){
                ta = headB;
            }
            else{
                ta = ta->next;
            }
            if(tb == NULL){
                tb = headA;
            }
            else{
                tb = tb->next;                
            }
        }
        
        return ta;
    }
};
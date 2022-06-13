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
        int n = 0;
        int m = 0;
        ListNode* ta = headA;
        ListNode* tb = headB;
        while(ta != NULL){
            ta = ta->next;
            n++;
        }
        while(tb != NULL){
            tb = tb->next;
            m++;
        }
        
        int diff = abs(m-n);
        ta = headA;
        tb = headB;
        if(n>m){
            while(diff > 0){
                ta = ta->next;
                diff--;  
            }
        }
        else{
            while(diff > 0){
                tb = tb->next;
                diff--;  
            }
        }
        
        while(ta != NULL){
            if(ta == tb){
                return ta;
            }
            ta = ta->next;
            tb = tb->next;
        }
        
        return NULL;
    }
};
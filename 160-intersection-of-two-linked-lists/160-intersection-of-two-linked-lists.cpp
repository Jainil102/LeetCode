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
        int a = 0;
        int b = 0;
        ListNode* ta = headA;
        ListNode* tb = headB;
        
        while(a==0 || b==0){
            ta = ta->next;
            tb = tb->next;
            if(ta == NULL && a==0){
                a = 1;
                ta = headB;
            }
            if(tb == NULL && b==0){
                b = 1;
                tb = headA;
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
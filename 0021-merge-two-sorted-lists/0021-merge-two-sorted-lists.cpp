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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p = list1;
        ListNode* q = list2;
        ListNode *temp1, *qprev;
        qprev = NULL;
        
        while(p!=NULL && q!=NULL){
            if(p->val <= q->val){
                if(qprev == NULL) list2 = p;
                else qprev->next = p;
                
                temp1 = p->next;
                p->next = q;
                qprev = p;
                p = temp1; 
            }
            else {
                qprev = q;
                q = q->next;
            }   
        }
        
        if(p != NULL){
            if(qprev == NULL) return p;
            qprev->next = p;
        }
        
        return list2;
    }
};
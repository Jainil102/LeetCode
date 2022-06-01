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
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        vector<ListNode*> a1;
        vector<ListNode*> a2;
        
        while(t1 != NULL){
            a1.push_back(t1);
            t1 = t1->next;
        }
        while(t2 != NULL){
            a2.push_back(t2);
            t2 = t2->next;
        }
        
        while(a1.back() == a2.back()){
            a1.pop_back();
            a2.pop_back();
            if(a1.size() == 0 && a2.size() != 0){
                return headA;
            }
            if(a1.size() != 0 && a2.size() == 0){
                return headB;
            }
            if(a1.size() == 0 && a2.size() == 0){
                return headA;
            }
        }
        return a1.back()->next;
    }
};
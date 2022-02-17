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
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int c1=0,c2=0;
        while(l1 != NULL || l2 != NULL){
            int a = carry;
            if(l1){
                a += l1->val;
            }
            if(l2){
                a += l2->val;
            }
            carry = (a - (a%10))/10;
            a = a%10;
            
            if(l1){
                l1->val = a;
                p1 = l1;
                l1 = l1->next;
                c1++;
            }
            if(l2){
                l2->val = a;
                p2 = l2;
                l2 = l2->next;
                c2++;
            }
            if(!l1 && !l2 && carry!=0){
                ListNode* temp = new ListNode();
                temp->val = carry;
                temp->next = NULL;
                p1->next = temp;
                p2->next = temp;
            }
        }
        ListNode* ans;
        if(c1>=c2){
            ans = t1;
        }
        else{
            ans = t2;
        }
        return ans;
    }
};
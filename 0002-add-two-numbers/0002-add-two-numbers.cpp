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
        ListNode* ans = new ListNode(0);
        int carry = 0;
        int a,b,sum;
        ListNode* prev = ans;
        
        while(l1!=NULL || l2!=NULL || carry!=0){
            a = l1!=NULL ? l1->val : 0;
            b = l2!=NULL ? l2->val : 0;
            sum = a+b+carry;
            carry = sum/10;
            
            prev->next = new ListNode(sum%10);
            prev = prev->next;
                                    
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }
        
        return ans->next;
    }
};
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
        ListNode* ans = NULL;
        int carry = 0;
        int a,b,sum;
        ListNode* prev = ans;
        
        while(l1!=NULL || l2!=NULL){
            a = l1!=NULL ? l1->val : 0;
            b = l2!=NULL ? l2->val : 0;
            sum = a+b+carry;
            carry = sum/10;
            
            ListNode* newNode = new ListNode(sum%10);
            if(prev == NULL) ans = newNode;
            else prev->next = newNode;
            prev = newNode;
                                    
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }
        
        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            prev->next = newNode;
        }
        
        return ans;
    }
};
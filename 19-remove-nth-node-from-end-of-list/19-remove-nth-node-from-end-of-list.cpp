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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        
        n = len-n+1;
        
        if(n==1){
            head = head->next;
            return head;
        }
        
        temp = head;
        for(int i=1; i<=n-2; i++){
            temp = temp->next;    
        }
        temp->next = (temp->next)->next;
        return head;
    }
};